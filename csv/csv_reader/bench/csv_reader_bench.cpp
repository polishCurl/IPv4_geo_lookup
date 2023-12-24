#include "benchmark/benchmark.h"
#include "src/csv_reader.hpp"

using namespace csv;

template <class... Args>
void BM_CsvReader(benchmark::State& state, Args&&... args) {
  const auto args_tuple = std::make_tuple(std::move(args)...);
  std::size_t rows_processed = 0;

  while (state.KeepRunning()) {
    CsvReader csv_reader{std::get<0>(args_tuple)};

    while (csv_reader.next()) {
      rows_processed++;
      auto& csv_row = csv_reader.get();
      const auto csv_row_size = csv_row.size();

      for (int i = 0; i < csv_row_size; i++) {
        benchmark::DoNotOptimize(csv_row[i]);
      }
    }

    benchmark::ClobberMemory();
  }

  // Get the number of values in a row (assumes all rows have same size)
  CsvReader csv_reader{std::get<0>(args_tuple)};
  csv_reader.next();
  const auto row_size = csv_reader.get().size();

  state.SetItemsProcessed(rows_processed * row_size);
}

BENCHMARK_CAPTURE(BM_CsvReader, geographic_units,
                  "csv/csv_reader/bench/data/"
                  "geographic-units-by-industry-and-statistical-area-2000-2023-"
                  "descending-order-february-2023.csv");

BENCHMARK_CAPTURE(BM_CsvReader, geolite2_country_ipv4,
                  "csv/csv_reader/bench/data/geolite2-country-ipv4.csv");

BENCHMARK_CAPTURE(BM_CsvReader, gross_domestic_product,
                  "csv/csv_reader/bench/data/"
                  "gross-domestic-product-september-2023-quarter.csv");
