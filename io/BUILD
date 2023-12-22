cc_library(
    name = "io_manager",
    hdrs = [
        "io_manager.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "io_manager_factory",
    hdrs = [
        "io_manager_factory.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
    deps = [
        ":io_manager",
        "//io/stdio_manager",
    ],
)
