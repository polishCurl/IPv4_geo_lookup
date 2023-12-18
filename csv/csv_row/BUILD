cc_library(
    name = "csv_row",
    srcs = [
        "src/csv_row.cpp",
    ],
    hdrs = [
        "src/csv_row.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//csv/csv_reader:__subpackages__"],
    deps = ["//csv:csv_row_interface"],
)

cc_test(
    name = "csv_row_test",
    srcs = ["test/csv_row_test.cpp"],
    deps = [
        ":csv_row",
        "@googletest//:gtest_main",
    ],
)
