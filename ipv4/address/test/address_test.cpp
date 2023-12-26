#include "ipv4/address.hpp"

#include <string>

#include "gtest/gtest.h"

using namespace ipv4;

TEST(Ipv4Address, StringConstructor) {
  EXPECT_EQ(0, ipv4::Address("0.0.0.0").ip_);
  EXPECT_EQ(4294967295, ipv4::Address("255.255.255.255").ip_);
  EXPECT_EQ(1345575498, ipv4::Address("80.51.218.74").ip_);
  EXPECT_EQ(16843009, ipv4::Address("1.1.1.1").ip_);
  EXPECT_EQ(16715136, ipv4::Address("0.255.13.128").ip_);
}

TEST(Ipv4Address, Constructor) {
  EXPECT_EQ(0xabcdef11, ipv4::Address{0xabcdef11}.ip_);
}

TEST(Ipv4Address, ToString) {
  EXPECT_EQ(std::string{ipv4::Address{0}}, "0.0.0.0");
  EXPECT_EQ(std::string{ipv4::Address{4294967295}}, "255.255.255.255");
  EXPECT_EQ(std::string{ipv4::Address{1345575498}}, "80.51.218.74");
  EXPECT_EQ(std::string{ipv4::Address{16843009}}, "1.1.1.1");
  EXPECT_EQ(std::string{ipv4::Address{16715136}}, "0.255.13.128");
}
