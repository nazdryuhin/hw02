#include <gtest/gtest.h>
#include "filters.cpp"

std::vector<IpAddress> in_ip = {
    {{"222", "173", "235", "246"}},
    {{"222", "130", "177", "64"}},
    {{"222", "82", "198", "61"}},
    {{"46", "70", "225", "39"}},
    {{"46", "70", "147", "26"}},
    {{"46", "70", "113", "73"}},
    {{"46", "70", "29", "76"}},
    {{"1", "70", "44", "170"}},
    {{"1", "29", "168", "152"}},
    {{"1", "1", "234", "8"}}
};

bool compare(const std::vector<IpAddress> &out_ip, const std::vector<IpAddress> &out_etalon){
    bool result = true;
    if(out_ip.size() == out_etalon.size()){
        auto iter_out_etalon = out_etalon.begin();
        for(const auto& ip : out_ip) {
            result = (result && (ip == *iter_out_etalon));
            //std::cout << ip << " == "<< *iter_out_etalon << " -> " << result << std::endl;
            ++iter_out_etalon;
        }
    }else {
        result = false;
    }
    return result;
}

TEST (FiltersTest, FilterAny){
    auto out_ip = FilterAny(in_ip, 1);
    std::vector<IpAddress> out_etalon1 = {
        {{"1", "70", "44", "170"}},
        {{"1", "29", "168", "152"}},
        {{"1", "1", "234", "8"}}
    };
    EXPECT_TRUE (compare(out_ip, out_etalon1));

    out_ip = FilterAny(in_ip, 170);
    std::vector<IpAddress> out_etalon2 = {
        {{"1", "70", "44", "170"}}
    };
    EXPECT_TRUE (compare(out_ip, out_etalon2));

    out_ip = FilterAny(in_ip, 255);
    std::vector<IpAddress> out_etalon3 = {};
    EXPECT_TRUE (compare(out_ip, out_etalon3));
}
