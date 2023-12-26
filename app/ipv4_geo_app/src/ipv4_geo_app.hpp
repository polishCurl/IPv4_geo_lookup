#ifndef APP_IPV4_GEO_APP_SRC_IPV4_GEO_APP_HPP_
#define APP_IPV4_GEO_APP_SRC_IPV4_GEO_APP_HPP_

#include <map>
#include <vector>

#include "app/iapp.hpp"
#include "io/io_manager.hpp"

namespace app {

/// Tokenized user input
using Args = std::vector<std::string>;

/// User input handler funtion
using Handler = std::function<void(const Args&)>;

/// Mapping from command name to the handler function
using Parser = std::map<std::string, Handler>;

/**
 * \brief Network geolocation lookup application implementation.
 */
class Ipv4GeoApp : public IApp {
 public:
  Ipv4GeoApp();
  Ipv4GeoApp(const Ipv4GeoApp&) = delete;
  Ipv4GeoApp(Ipv4GeoApp&&) = delete;
  Ipv4GeoApp& operator=(const Ipv4GeoApp&) = delete;
  Ipv4GeoApp& operator=(Ipv4GeoApp&&) = delete;
  ~Ipv4GeoApp() = default;

  bool initialize() override;
  bool run() override;

 protected:
  void ack();

  io::IOManager* io_manager_;  //*!< Application's IO manager
  const Parser parser_;        //*!< Application's IO manager

  static constexpr char const* kExitCommand{"EXIT"};
  static constexpr char const* kLoadCommand{"LOAD"};
  static constexpr char const* kLookupCommand{"LOOKUP"};
};

}  // namespace app

#endif  // APP_IPV4_GEO_APP_SRC_IPV4_GEO_APP_HPP_
