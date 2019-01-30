#pragma once
#include <vector>
#include <algorithm>

#include "ip_class.h"

std::vector<IpAddress> FilterAny(const std::vector<IpAddress> &ip_pool, int mask);

template<typename... Mask>
std::vector<IpAddress> Filter (const std::vector<IpAddress> &ip_pool, Mask... mask);

template<typename... Mask>
std::vector<IpAddress> FilterForSortedData (const std::vector<IpAddress> &ip_pool, Mask... mask);

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

template<typename... Mask>
std::vector<IpAddress> FilterForSortedData (const std::vector<IpAddress> &ip_pool, Mask... mask) {
    std::vector<IpAddress> result_ip_pool;

    IpAddress min_ip_equal_mask, max_ip_equal_mask;
    min_ip_equal_mask.by_mask( mask... , 0);
    max_ip_equal_mask.by_mask( mask... , 255);

    auto lower_bound = std::lower_bound(rbegin(ip_pool), rend(ip_pool), min_ip_equal_mask);
    auto upper_bound = std::upper_bound(rbegin(ip_pool), rend(ip_pool), max_ip_equal_mask);

    for(auto ip = (upper_bound - 1); ip >= lower_bound; --ip) {
        result_ip_pool.push_back(*ip);
    }
    return result_ip_pool;
}
