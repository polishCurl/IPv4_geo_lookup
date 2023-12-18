#include "csv_row.hpp"

#include <sstream>
#include <string>
#include <vector>

namespace csv {

CsvRow::CsvRow(const std::string_view& line)
    : line_{[&line]() {
        if (line[line.size() - 1] == ',') {
          return line.substr(0, line.size() - 1);
        }
        return line;
      }()} {
  comma_indexes_.emplace_back(-1);
  if (line_.empty()) {
    return;
  }

  std::string::size_type pos = 0;
  while ((pos = line_.find(',', pos)) != std::string::npos) {
    comma_indexes_.emplace_back(pos++);
  }

  pos = line_.size();
  comma_indexes_.emplace_back(pos);
}

CsvRow::CsvRow(const CsvRow& other)
    : line_{other.line_}, comma_indexes_{other.comma_indexes_} {}

CsvRow::CsvRow(CsvRow&& other)
    : line_{std::move(other.line_)},
      comma_indexes_{std::move(other.comma_indexes_)} {}

CsvRow& CsvRow::operator=(const CsvRow& other) {
  line_ = other.line_;
  comma_indexes_ = other.comma_indexes_;
  return *this;
}

CsvRow& CsvRow::operator=(CsvRow&& other) {
  line_ = std::move(other.line_);
  comma_indexes_ = std::move(other.comma_indexes_);
  return *this;
}

std::string_view CsvRow::operator[](std::size_t index) const {
  if (index >= this->size()) {
    std::stringstream error_msg;
    error_msg << "Invalid index: " << index << " (Row size: " << this->size()
              << ')';
    throw std::invalid_argument(error_msg.str());
  }

  const auto start_index = comma_indexes_[index] + 1;
  const auto end_index = comma_indexes_[index + 1];
  return std::string_view(&line_[start_index], end_index - start_index);
}

std::size_t CsvRow::size() const { return comma_indexes_.size() - 1; }

}  // namespace csv
