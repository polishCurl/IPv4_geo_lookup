#include "src/csv_row.hpp"

#include "gtest/gtest.h"

using namespace csv;

TEST(CsvRowTest, EmptyLine) {
  CsvRow row{""};
  ASSERT_EQ(row.size(), 0);
  ASSERT_THROW(row[0], std::invalid_argument);
}

TEST(CsvRowTest, OneValue) {
  CsvRow row{"1"};
  ASSERT_EQ(row.size(), 1);
  EXPECT_EQ(row[0], "1");
  ASSERT_THROW(row[1], std::invalid_argument);
}

TEST(CsvRowTest, OneValueTrailingComma) {
  CsvRow row{"1,"};
  ASSERT_EQ(row.size(), 1);
  EXPECT_EQ(row[0], "1");
  ASSERT_THROW(row[1], std::invalid_argument);
}

TEST(CsvRowTest, TwoValues) {
  CsvRow row{"1,2"};
  ASSERT_EQ(row.size(), 2);
  EXPECT_EQ(row[0], "1");
  EXPECT_EQ(row[1], "2");
  ASSERT_THROW(row[2], std::invalid_argument);
}

TEST(CsvRowTest, TwoValuesTralingComma) {
  CsvRow row{"first value,2.4561,"};
  ASSERT_EQ(row.size(), 2);
  EXPECT_EQ(row[0], "first value");
  EXPECT_EQ(row[1], "2.4561");
  ASSERT_THROW(row[2], std::invalid_argument);
}