#pragma once
#include <vector>

#include "ip_class.h"

std::vector<IpAddress> FilterAny(const std::vector<IpAddress> &ip_pool, int mask);
