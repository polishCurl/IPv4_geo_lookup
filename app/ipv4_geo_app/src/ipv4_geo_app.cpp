#include "ipv4_geo_app.hpp"

#include <sstream>

#include "io/io_manager_factory.hpp"

namespace app {

Ipv4GeoApp::Ipv4GeoApp()
    : io_manager_{io::IOManagerFactory::create()},
      parser_{{kExitCommand,
               [this](const Args& args) {
                 this->ack();
                 std::exit(EXIT_SUCCESS);
               }},
              {kLoadCommand,
               [this](const Args& args) {
                 // TODO: Implement load() command
                 this->ack();
               }},
              {kLookupCommand, [this](const Args& args) {
                 // TODO: Implement lookup() command
                 this->ack();
               }}} {}

bool Ipv4GeoApp::initialize() { return true; }

bool Ipv4GeoApp::run() {
  while (true) {
    std::string input = io_manager_->read();
    std::istringstream string_stream(input);
    Args args((std::istream_iterator<std::string>(string_stream)),
              std::istream_iterator<std::string>());

    if (args.empty() || (parser_.find(args[0]) == parser_.end())) {
      io_manager_->write("ERROR!");
    } else {
      parser_.at(args[0])(args);
    }
  }

  return true;
}

void Ipv4GeoApp::ack() { io_manager_->write("OK"); }

}  // namespace app
