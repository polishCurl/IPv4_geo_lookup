#ifndef IPV4_NETWORK_HPP_
#define IPV4_NETWORK_HPP_

#include <cstdint>
#include <string>

#include "address.hpp"

namespace ipv4 {

using Prefix = std::uint16_t;

struct Network {
  Network(const std::string& str);
  Network(Address address, Prefix prefix_length = 0) noexcept;
  operator std::string() const;
  void setCommonPrefix(const Network& other);

  Address address_;
  Prefix prefix_length_;
};

}  // namespace ipv4

#endif  // IPV4_NETWORK_HPP_
