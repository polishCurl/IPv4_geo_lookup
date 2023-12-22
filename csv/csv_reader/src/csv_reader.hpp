#ifndef IPV4_GEO_LOOKUP_CSV_CSV_READER_SRC_CSV_READER_HPP_
#define IPV4_GEO_LOOKUP_CSV_CSV_READER_SRC_CSV_READER_HPP_

#include <fstream>

#include "csv/csv_row/src/csv_row.hpp"
#include "csv/icsv_reader.hpp"
#include "csv/icsv_row.hpp"

namespace csv {

/**
 * \brief CSV file reader implementation.
 */
class CsvReader : public ICsvReader {
 public:
  CsvReader(std::string filename);
  CsvReader(const CsvReader&) = delete;
  CsvReader(CsvReader&&) = delete;
  CsvReader& operator=(const CsvReader&) = delete;
  CsvReader& operator=(CsvReader&&) = delete;
  ~CsvReader();

  bool next() noexcept override;
  ICsvRow& get() noexcept override;

 protected:
  std::ifstream stream_;  //*!< For reading CSV file
  std::string line_;      //*!< Current CSV file line being parsed
  CsvRow row_;            //*!< Read-only CSV row view of the current line_
};

}  // namespace csv

#endif  // IPV4_GEO_LOOKUP_CSV_CSV_READER_SRC_CSV_READER_HPP_
