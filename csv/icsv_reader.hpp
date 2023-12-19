#ifndef IPV4_GEO_LOOKUP_CSV_ICSV_READER_HPP_
#define IPV4_GEO_LOOKUP_CSV_ICSV_READER_HPP_

#include "csv/icsv_row.hpp"

namespace csv {

/**
 * \brief CSV reader interface.
 */
class ICsvReader {
 public:
  virtual ~ICsvReader() = default;

  /**
   * \brief Move to the next row.
   *
   * \return True if the iterator has been sucessfully moved, false otherwise.
   */

  virtual bool next() noexcept = 0;

  /**
   * \brief Get read-only access to the current CSV row.
   *
   * \return CSV row view.
   */
  virtual ICsvRow& get() noexcept = 0;
};

}  // namespace csv

#endif  // IPV4_GEO_LOOKUP_CSV_ICSV_READER_HPP_
