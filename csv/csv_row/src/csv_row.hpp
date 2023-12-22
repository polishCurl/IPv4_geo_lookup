#ifndef CSV_CSV_ROW_SRC_CSV_ROW_HPP_
#define CSV_CSV_ROW_SRC_CSV_ROW_HPP_

#include <string>
#include <vector>

#include "csv/icsv_row.hpp"

namespace csv {

/**
 * \brief CSV row view implementation.
 */
class CsvRow : public ICsvRow {
 public:
  CsvRow(const std::string_view& line) noexcept;
  CsvRow(const CsvRow& other) noexcept;
  CsvRow(CsvRow&& other) noexcept;
  CsvRow& operator=(const CsvRow& other) noexcept;
  CsvRow& operator=(CsvRow&&) noexcept;

  std::string_view operator[](std::size_t index) const override;
  std::size_t size() const noexcept override;

 protected:
  std::string_view line_;           //*!< Read-only view of CSV file line
  std::vector<int> comma_indexes_;  //*!< List of comma (',') positions in line_
};

}  // namespace csv

#endif  // CSV_CSV_ROW_SRC_CSV_ROW_HPP_
