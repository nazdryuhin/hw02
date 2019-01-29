#pragma once
#include <vector>

#include "ip_class.h"

std::vector<IpAddress> FilterAny(const std::vector<IpAddress> &ip_pool, int mask);

template<typename... Mask>
std::vector<IpAddress> Filter (const std::vector<IpAddress> &ip_pool, Mask... mask);

template<typename... Mask>                                                  
std::vector<IpAddress> Filter (const std::vector<IpAddress> &ip_pool, Mask... mask) {                                                                 
    std::vector<IpAddress> result_ip_pool;                                 
    for(const auto& ip : ip_pool) {                                         
        if(ip.equal_mask( mask... )) {                                      
            result_ip_pool.push_back(ip);                                   
        }                                                                   
    }                                                                       
    return result_ip_pool;                                                  
}        
