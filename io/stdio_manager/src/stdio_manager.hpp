#ifndef IO_STDIO_MANAGER_SRC_STDIO_MANAGER_HPP_
#define IO_STDIO_MANAGER_SRC_STDIO_MANAGER_HPP_

#include <string>

#include "io/io_manager.hpp"

namespace io {

/**
 * \brief Standard IO manager implementation.
 */
class StdioManager : public IOManager {
 public:
  StdioManager(const StdioManager&) = delete;
  StdioManager(StdioManager&&) = delete;
  StdioManager& operator=(const StdioManager&) = delete;
  StdioManager& operator=(StdioManager&&) = delete;
  ~StdioManager() = default;

  /**
   * \brief Get standard IO manager instance.
   *
   * \return Pointer to StdioManager.
   */
  static StdioManager* getInstance();

  /**
   * \brief Read a line from standard input stream.
   *
   * \return Line read.
   */
  std::string read() noexcept override;

  /**
   * \brief Write to standard output stream.
   *
   * \param output String to write.
   */
  void write(const std::string& output) noexcept override;

 protected:
  StdioManager() = default;

  /// standard IO manager instance
  static std::unique_ptr<StdioManager> stdio_manager_;
};

}  // namespace io

#endif  // IO_STDIO_MANAGER_SRC_STDIO_MANAGER_HPP_
