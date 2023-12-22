#include "io/stdio_manager/src/stdio_manager.hpp"

#include "gtest/gtest.h"

using namespace io;

class StdioManagerRedirectTest : public ::testing::Test {
 protected:
  std::streambuf* cin_rdbuf_{};
  std::streambuf* cout_rdbuf_{};
  std::istringstream input_stream_{};
  std::ostringstream output_stream_{};
  StdioManager* stdio_manager_{};

  void SetUp() override {
    cin_rdbuf_ = std::cin.rdbuf(input_stream_.rdbuf());
    ASSERT_NE(cin_rdbuf_, nullptr);
    cout_rdbuf_ = std::cout.rdbuf(output_stream_.rdbuf());
    ASSERT_NE(cout_rdbuf_, nullptr);
    stdio_manager_ = StdioManager::getInstance();
    ASSERT_NE(stdio_manager_, nullptr);
  }

  void TearDown() override {
    output_stream_.str(std::string{});
    std::cin.rdbuf(cin_rdbuf_);
    std::cout.rdbuf(cout_rdbuf_);
  }
};

TEST(StdioManagerTest, getInstance) {
  auto stdio_manager = StdioManager::getInstance();
  ASSERT_NE(stdio_manager, nullptr);
  auto another_stdio_manager = StdioManager::getInstance();
  ASSERT_EQ(stdio_manager, another_stdio_manager);
}

TEST_F(StdioManagerRedirectTest, Write) {
  stdio_manager_->write("OK");
  ASSERT_EQ(output_stream_.str(), "> OK\n");
}

TEST_F(StdioManagerRedirectTest, WriteMultipleWords) {
  stdio_manager_->write("US, California");
  ASSERT_EQ(output_stream_.str(), "> US, California\n");
}

TEST_F(StdioManagerRedirectTest, Read) {
  input_stream_.str("EXIT");
  auto input = stdio_manager_->read();
  ASSERT_EQ(input, "EXIT");
}

TEST_F(StdioManagerRedirectTest, ReadMultipleWords) {
  input_stream_.str("LOOKUP 71.8.28.3");
  auto input = stdio_manager_->read();
  ASSERT_EQ(input, "LOOKUP 71.8.28.3");
}