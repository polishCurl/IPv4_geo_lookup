#include "src/csv_reader.hpp"

#include <fstream>
#include <iostream>

#include "gtest/gtest.h"

using namespace csv;

inline bool file_exists(const std::string& name) {
  std::ifstream f(name.c_str());
  return f.good();
}

TEST(CsvReaderTest, EmptyFile) {
  const std::string kInputCsvFile{"csv/csv_reader/test/data/empty.csv"};
  ASSERT_TRUE(file_exists(kInputCsvFile));
  CsvReader csv_reader{kInputCsvFile};
  ICsvRow& row = csv_reader.get();
  ASSERT_EQ(row.size(), 0);
  ASSERT_FALSE(csv_reader.next());
  ASSERT_FALSE(csv_reader.next());
  ASSERT_EQ(row.size(), 0);
}

TEST(CsvReaderTest, OneLine) {
  const std::string kInputCsvFile{"csv/csv_reader/test/data/one_line.csv"};
  ASSERT_TRUE(file_exists(kInputCsvFile));
  CsvReader csv_reader{kInputCsvFile};
  ASSERT_TRUE(csv_reader.next());
  ICsvRow& row = csv_reader.get();
  ASSERT_EQ(row.size(), 1);
  ASSERT_EQ(row[0], "single_value");
  ASSERT_FALSE(csv_reader.next());
  ASSERT_FALSE(csv_reader.next());
  row = csv_reader.get();
  ASSERT_EQ(row.size(), 1);
  ASSERT_EQ(row[0], "single_value");
}