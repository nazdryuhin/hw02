#include <gtest/gtest.h>
#include "ip_class.cpp"


TEST (EqualAnuFieldTest, test) {
    IpAddress ip = {{"39", "46", "86", "85"}};

    EXPECT_TRUE (ip.equal_any_field(86));
    
    EXPECT_FALSE (ip.equal_any_field(30));
    EXPECT_FALSE (ip.equal_any_field(256));
    EXPECT_FALSE (ip.equal_any_field(-1));

}

