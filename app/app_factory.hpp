#ifndef APP_APP_FACTORY_HPP_
#define APP_APP_FACTORY_HPP_

#include "app/ipv4_geo_app/src/ipv4_geo_app.hpp"
#include "iapp.hpp"

namespace app {

/**
 * \brief Factory for objects implementing IApp interface.
 */
class AppFactory {
 public:
  /**
   * \brief Create IApp instance.
   *
   * \return Pointer to object implementing IApp interface.
   */
  static std::unique_ptr<IApp> create() {
    return std::make_unique<Ipv4GeoApp>();
  };
};

}  // namespace app

#endif  // APP_APP_FACTORY_HPP_
