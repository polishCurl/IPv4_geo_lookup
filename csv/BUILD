cc_library(
    name = "csv_row_interface",
    hdrs = [
        "icsv_row.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "csv_reader_interface",
    hdrs = [
        "icsv_reader.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "csv_reader_factory",
    hdrs = [
        "csv_reader_factory.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
    deps = [
        ":csv_reader_interface",
        "//csv/csv_reader",
    ],
)
