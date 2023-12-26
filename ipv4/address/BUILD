cc_library(
    name = "address_impl",
    srcs = [
        "src/address.cpp",
    ],
    strip_include_prefix = "",
    visibility = ["//ipv4:__subpackages__"],
    deps = [
        "//ipv4:address",
        "@boost//:asio",
    ],
)

cc_test(
    name = "address_test",
    srcs = ["test/address_test.cpp"],
    deps = [
        ":address_impl",
        "@googletest//:gtest_main",
    ],
)
