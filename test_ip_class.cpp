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
