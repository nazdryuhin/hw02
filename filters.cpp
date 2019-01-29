#include "filters.h"

#include <vector>
#include "ip_class.h"

std::vector<IpAddress> FilterAny(const std::vector<IpAddress> &ip_pool, int mask) {
    std::vector<IpAddress> result_ip_pool;
    for(const auto& ip : ip_pool) {
        if(ip.equal_any_field(mask)) {
            result_ip_pool.push_back(ip);
        }
    }
    return result_ip_pool;
}
