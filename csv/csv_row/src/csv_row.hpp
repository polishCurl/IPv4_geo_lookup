#ifndef IPV4_GEO_LOOKUP_CSV_SRC_CSV_ROW_CSV_ROW_HPP_
#define IPV4_GEO_LOOKUP_CSV_SRC_CSV_ROW_CSV_ROW_HPP_

#include <string>
#include <vector>

#include "csv/icsv_row.hpp"

namespace csv {

class CsvRow : public ICsvRow {
 public:
  CsvRow(const std::string_view& line);
  CsvRow(const CsvRow& other);
  CsvRow(CsvRow&& other);
  CsvRow& operator=(const CsvRow& other);
  CsvRow& operator=(CsvRow&&);

  std::string_view operator[](std::size_t index) const override;
  std::size_t size() const override;

 protected:
  std::string_view line_;
  std::vector<int> comma_indexes_;
};

}  // namespace csv

#endif  // IPV4_GEO_LOOKUP_CSV_SRC_CSV_ROW_CSV_ROW_HPP_
