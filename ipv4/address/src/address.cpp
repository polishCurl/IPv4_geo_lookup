#include "ipv4/address.hpp"

#include <boost/asio/ip/address_v4.hpp>
#include <sstream>

namespace ipv4 {

Address::Address(const std::string& str) {
  try {
    ip_ = boost::asio::ip::make_address_v4(str).to_uint();
  } catch (...) {
    std::stringstream error_msg;
    error_msg << "Invalid input Network address: " << str;
    throw std::invalid_argument(error_msg.str());
  }
}

Address::Address(Ip ip) noexcept : ip_{ip} {}

Address::operator std::string() const {
  return boost::asio::ip::address_v4(ip_).to_string();
}

}  // namespace ipv4
