#include "ipv4/network.hpp"

#include <string>

#include "gtest/gtest.h"

using namespace ipv4;

TEST(Ipv4Network, StringConstructor) {
  EXPECT_EQ(0, ipv4::Network("0.0.0.0/24").address_.ip_);
  EXPECT_EQ(4294967295, ipv4::Network("255.255.255.255/8").address_.ip_);
  EXPECT_EQ(1345575498, ipv4::Network("80.51.218.74/1").address_.ip_);
  EXPECT_EQ(16843009, ipv4::Network("1.1.1.1/0").address_.ip_);
  EXPECT_EQ(16715136, ipv4::Network("0.255.13.128/31").address_.ip_);
  EXPECT_EQ(16715136, ipv4::Network("0.255.13.128/32").address_.ip_);

  EXPECT_EQ(24, ipv4::Network("0.0.0.0/24").prefix_length_);
  EXPECT_EQ(8, ipv4::Network("255.255.255.255/8").prefix_length_);
  EXPECT_EQ(1, ipv4::Network("80.51.218.74/1").prefix_length_);
  EXPECT_EQ(0, ipv4::Network("1.1.1.1/0").prefix_length_);
  EXPECT_EQ(31, ipv4::Network("0.255.13.128/31").prefix_length_);
  EXPECT_EQ(32, ipv4::Network("0.255.13.128/32").prefix_length_);
}

TEST(Ipv4Network, Constructor) {
  auto network = ipv4::Network{0xabcdef11, 13};
  EXPECT_EQ(0xabcdef11, network.address_.ip_);
  EXPECT_EQ(13, network.prefix_length_);
}

TEST(Ipv4Network, ToString) {
  EXPECT_EQ(std::string{ipv4::Network{"0.0.0.0/24"}}, "0.0.0.0/24");
  EXPECT_EQ(std::string{ipv4::Network{"255.255.255.255/8"}},
            "255.255.255.255/8");
  EXPECT_EQ(std::string{ipv4::Network{"80.51.218.74/1"}}, "80.51.218.74/1");
  EXPECT_EQ(std::string{ipv4::Network{"1.1.1.1/0"}}, "1.1.1.1/0");
  EXPECT_EQ(std::string{ipv4::Network{"0.255.13.128/31"}}, "0.255.13.128/31");
  EXPECT_EQ(std::string{ipv4::Network{"0.255.13.128/32"}}, "0.255.13.128/32");
}