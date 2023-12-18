cc_library(
    name = "csv_reader",
    srcs = [
        "src/csv_reader.cpp",
    ],
    hdrs = [
        "src/csv_reader.hpp",
    ],
    strip_include_prefix = "",
    deps = [
        "//csv:csv_reader_interface",
        "//csv/csv_row",
    ],
)

cc_test(
    name = "csv_reader_test",
    srcs = ["test/csv_reader_test.cpp"],
    data = glob(["test/data/*.csv"]),
    deps = [
        ":csv_reader",
        "@googletest//:gtest_main",
    ],
)
