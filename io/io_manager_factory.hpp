#ifndef IO_IO_MANAGER_FACTORY_HPP_
#define IO_IO_MANAGER_FACTORY_HPP_

#include "io/stdio_manager/src/stdio_manager.hpp"
#include "io_manager.hpp"

namespace io {

class IOManagerFactory {
 public:
  IOManager* create() const { return StdioManager::getInstance(); };
};

}  // namespace io

#endif  // IO_IO_MANAGER_FACTORY_HPP_
