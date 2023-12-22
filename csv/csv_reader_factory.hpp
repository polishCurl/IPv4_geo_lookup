#ifndef CSV_CSV_READER_FACTORY_HPP_
#define CSV_CSV_READER_FACTORY_HPP_

#include "csv/csv_reader/src/csv_reader.hpp"
#include "icsv_reader.hpp"

namespace csv {

/**
 * \brief Factory for objects implementing ICsvReader interface.
 */
class CsvReaderFactory {
 public:
  /**
   * \brief Create ICsvReader instance.
   *
   * \return Pointer to object implementing ICsvReader interface.
   */
  static std::unique_ptr<ICsvReader> create() {
    return std::make_unique<CsvReader>();
  };
};

}  // namespace csv

#endif  // CSV_CSV_READER_FACTORY_HPP_
