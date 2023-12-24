#ifndef APP_IAPP_HPP_
#define APP_IAPP_HPP_

namespace app {

/**
 * \brief Application interface.
 */
class IApp {
 public:
  virtual ~IApp() = default;

  /**
   * \brief Initialize application.
   *
   * \return True if application initialized successfully, false otherwise.
   */
  virtual bool initialize() = 0;

  /**
   * \brief Run application.
   *
   * \return True if application ran successfully, false otherwise.
   */
  virtual bool run() = 0;
};

}  // namespace app

#endif  // APP_IAPP_HPP_
