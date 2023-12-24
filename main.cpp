#include "app/app_factory.hpp"

int main() {
  auto app = app::AppFactory::create();
  app->initialize();
  app->run();
  return 0;
}