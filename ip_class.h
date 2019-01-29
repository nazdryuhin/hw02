#pragma once

#include <vector>
#include <array>
#include <string>

class IpAddress {                                                         
public:
    IpAddress();                                     
    IpAddress(const std::vector<std::string>& ip_vstr);                    
private:
    std::array<int, 4> addr = {0, 0, 0, 0};                                 
};
