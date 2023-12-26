#include "ipv4/network.hpp"

#include <bit>
#include <boost/asio/ip/network_v4.hpp>
#include <sstream>

namespace ipv4 {

Network::Network(const std::string& str) : address_{0} {
  try {
    const auto ip = boost::asio::ip::make_network_v4(str);
    address_ = ip.address().to_uint();
    prefix_length_ = ip.prefix_length();
  } catch (...) {
    std::stringstream error_msg;
    error_msg << "Invalid input Network address: " << str;
    throw std::invalid_argument(error_msg.str());
  }
}

Network::Network(Address address, Prefix prefix_length) noexcept
    : address_{address}, prefix_length_{prefix_length} {}

Network::operator std::string() const {
  return std::string(address_) + '/' + std::to_string(prefix_length_);
}

void Network::setCommonPrefix(const Network& other) {
  prefix_length_ = std::__countl_zero(address_.ip_ ^ other.address_.ip_);
}

}  // namespace ipv4
