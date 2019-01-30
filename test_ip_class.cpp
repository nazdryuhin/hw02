#include <gtest/gtest.h>
#include "ip_class.cpp"


TEST (EqualAnuFieldTest, test) {
    IpAddress ip = {{"39", "46", "86", "85"}};

    EXPECT_TRUE (ip.equal_any_field(86));
    
    EXPECT_FALSE (ip.equal_any_field(30));
    EXPECT_FALSE (ip.equal_any_field(256));
    EXPECT_FALSE (ip.equal_any_field(-1));

}

TEST (EqualMaskTest, test) {
    IpAddress ip = {{"39", "46", "86", "85"}};

    EXPECT_TRUE (ip.equal_mask(39, 46, 86, 85));
    EXPECT_TRUE (ip.equal_mask(39, 46, 86));
    EXPECT_TRUE (ip.equal_mask(39, 46));
    EXPECT_TRUE (ip.equal_mask(39));

    EXPECT_FALSE (ip.equal_mask(39, 46, 86, 85, 100));
    EXPECT_FALSE (ip.equal_mask(3, 46, 86, 85));
    EXPECT_FALSE (ip.equal_mask(39, 4, 86, 85));
    EXPECT_FALSE (ip.equal_mask(39, 46, 8, 85));
    EXPECT_FALSE (ip.equal_mask(39, 46, 86, 8));

}

TEST (ByMaskTest, test) {
    IpAddress ip;
    IpAddress ip_etalon1 = {{"12", "34", "56", "78"}};
    ip.by_mask(12, 34, 56, 78, 90);
    EXPECT_EQ (ip, ip_etalon1);

    IpAddress ip_etalon2 = {{"12", "34", "56", "78"}};
    ip.by_mask(12, 34, 56, 78);
    EXPECT_EQ (ip, ip_etalon2);

    IpAddress ip_etalon3 = {{"12", "34", "56", "56"}};
    ip.by_mask(12, 34, 56);
    EXPECT_EQ (ip, ip_etalon3);

    IpAddress ip_etalon4 = {{"12", "34", "34", "34"}};
    ip.by_mask(12, 34);
    EXPECT_EQ (ip, ip_etalon4);

    IpAddress ip_etalon5 = {{"12", "12", "12", "12"}};
    ip.by_mask(12);
    EXPECT_EQ (ip, ip_etalon5);
}
