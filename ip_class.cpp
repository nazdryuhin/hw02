#include "ip_class.h"

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <cassert>

IpAddress::IpAddress() : addr({0, 0, 0, 0}){}

IpAddress::IpAddress(const std::vector<std::string>& ip_vstr) {
    try {
        int i = 0;
        for(const auto& str : ip_vstr) {
            int val = boost::lexical_cast<int>(str);
            if((val < 0) || (val > 255)) {
                std::stringstream ss;
                ss << "ip_address::addr: erexpected data 0...255, but has: " << val;
                throw std::runtime_error(ss.str());
            }
            addr.at(i) = val;
            i++;
        }
    }
    catch(const boost::bad_lexical_cast &e) {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream& operator << (std::ostream& stream, const IpAddress& ip) {
    stream << ip.addr[0] << '.' << ip.addr[1] << '.' << ip.addr[2] << '.' << ip.addr[3];
    return stream;
}
