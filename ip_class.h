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
    bool equal_any_field(int mask) const;
private:
    std::array<int, 4> addr = {0, 0, 0, 0};                                 
};
