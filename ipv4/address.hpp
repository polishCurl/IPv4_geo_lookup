#ifndef IPV4_ADDRESS_HPP_
#define IPV4_ADDRESS_HPP_

#include <cstdint>
#include <string>

namespace ipv4 {

using Ip = std::uint32_t;

struct Address {
  Address(const std::string& str);
  Address(Ip ip) noexcept;
  operator std::string() const;

  Ip ip_;
};

}  // namespace ipv4

#endif  // IPV4_ADDRESS_HPP_
