#ifndef IPV4_GEO_LOOKUP_IO_IO_MANAGER_HPP_
#define IPV4_GEO_LOOKUP_IO_IO_MANAGER_HPP_

#include <string>

namespace io {

/**
 * \brief IO manager interface.
 */
class IOManager {
 public:
  virtual ~IOManager() = default;

  /**
   * \brief Read a line from input.
   *
   * \return Line read.
   */
  virtual std::string read() noexcept = 0;

  /**
   * \brief Write to output.
   *
   * \param output String to write.
   */
  virtual void write(const std::string& output) noexcept = 0;
};

}  // namespace io

#endif  // IPV4_GEO_LOOKUP_IO_IO_MANAGER_HPP_
