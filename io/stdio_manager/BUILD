cc_library(
    name = "stdio_manager",
    srcs = [
        "src/stdio_manager.cpp",
    ],
    hdrs = [
        "src/stdio_manager.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//app:__subpackages__"],
    deps = [
        "//io:io_manager",
    ],
)

cc_test(
    name = "stdio_manager_test",
    srcs = ["test/stdio_manager_test.cpp"],
    deps = [
        ":stdio_manager",
        "@googletest//:gtest_main",
    ],
)
