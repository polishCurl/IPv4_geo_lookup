#ifndef IPV4_GEO_LOOKUP_CSV_ICSV_ROW_HPP_
#define IPV4_GEO_LOOKUP_CSV_ICSV_ROW_HPP_

#include <string>

namespace csv {

/**
 * \brief CSV row view interface.
 */
class ICsvRow {
 public:
  virtual ~ICsvRow() = default;

  /**
   * \brief Read the n'th value in the given CSV row.
   *
   * \param[in] index Index of the value to read (zero-based).
   *
   * \return String view of the n'th value in the row.
   *
   * \exception std::invalid_argument Index is outside the valid range.
   */

  virtual std::string_view operator[](std::size_t index) const = 0;

  /**
   * \brief Get the number of values in the given CSV row.
   *
   * \return CSV row's value count.
   */
  virtual std::size_t size() const noexcept = 0;
};

}  // namespace csv

#endif  // IPV4_GEO_LOOKUP_CSV_ICSV_ROW_HPP_
