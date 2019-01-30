#pragma once

#include <vector>
#include <array>
#include <string>
#include <iostream>

class IpAddress {                                                         
public:
    IpAddress();                                     
    IpAddress(const std::vector<std::string>& ip_vstr);                    
    friend std::ostream& operator << (std::ostream& stream, const IpAddress& ip);
    friend bool operator < (const IpAddress& lhs, const IpAddress& rhs);
    friend bool operator == (const IpAddress& lhs, const IpAddress& rhs);
    bool equal_any_field(int mask) const;
    
    template<typename... Mask>                                              
    bool equal_mask(Mask... mask) const; 
    template<typename... Mask>
    void by_mask(Mask... mask);
private:

    friend bool equal_m(const IpAddress& ip, unsigned int iter);
    template<typename T, typename... Mask>
    friend bool equal_m(const IpAddress& ip, unsigned int iter, T t, Mask... mask);
    std::array<int, 4> addr = {0, 0, 0, 0};                                 
};

template<typename T, typename... Mask>
bool equal_m(const IpAddress& ip, unsigned int iter, T t, Mask... mask) {
    if(iter < ip.addr.size())
        return (t == ip.addr[iter]) && equal_m(ip, ++iter, mask...);
    return false;
}

template<typename... Mask>
bool IpAddress::equal_mask(Mask... mask) const {
    return equal_m(*this, 0, mask...);
}

template<typename... Mask>
void IpAddress::by_mask(Mask... mask) {
    try {                                                                   
        std::array <int, sizeof...(mask)> msk = {mask...};                  
        unsigned int i = 0;                                                          
        for(const auto& m : msk) {                                          
            addr.at(i) = m;                                        
            ++i;                                                            
        }
        while(i < addr.size()) {
            addr[i] = msk.back();
            ++i;
        }
    }                                                                       
    catch(const std::exception &e) {                                        
        std::cerr << e.what() << std::endl;                                 
    }             
}
