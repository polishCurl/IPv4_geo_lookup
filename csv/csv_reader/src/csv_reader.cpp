#include "csv_reader.hpp"

#include <fstream>
#include <string>

#include "csv/csv_row/src/csv_row.hpp"

namespace csv {

CsvReader::CsvReader(std::string filename)
    : stream_{filename, std::ifstream::in}, row_{""} {}

CsvReader::~CsvReader() { stream_.close(); }

bool CsvReader::next() {
  const auto line_read_ok = static_cast<bool>(std::getline(stream_, line_));
  if (line_read_ok) {
    row_ = CsvRow{line_};
  }
  return line_read_ok;
}

ICsvRow& CsvReader::get() { return row_; };

}  // namespace csv
