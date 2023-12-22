#include "stdio_manager.hpp"

#include <iostream>

namespace io {

std::unique_ptr<StdioManager> StdioManager::stdio_manager_{nullptr};

StdioManager* StdioManager::getInstance() {
  if (!stdio_manager_) {
    stdio_manager_ = std::unique_ptr<StdioManager>(new StdioManager{});
  }

  return stdio_manager_.get();
}

std::string StdioManager::read() noexcept {
  std::string input;
  std::getline(std::cin, input);
  return input;
}

void StdioManager::write(const std::string& output) noexcept {
  std::cout << "> " << output << "\n";
}

}  // namespace io