#ifndef IO_IO_MANAGER_FACTORY_HPP_
#define IO_IO_MANAGER_FACTORY_HPP_

#include "io/stdio_manager/src/stdio_manager.hpp"
#include "io_manager.hpp"

namespace io {

/**
 * \brief Factory for objects implementing IOManager interface.
 */
class IOManagerFactory {
 public:
  /**
   * \brief Create IOManager instance.
   *
   * \return Pointer to object implementing IOManager interface.
   */
  static IOManager* create() { return StdioManager::getInstance(); };
};

}  // namespace io

#endif  // IO_IO_MANAGER_FACTORY_HPP_
