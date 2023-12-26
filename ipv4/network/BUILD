cc_library(
    name = "network_impl",
    srcs = [
        "src/network.cpp",
    ],
    strip_include_prefix = "",
    deps = [
        "//ipv4:network",
        "//ipv4/address:address_impl",
        "@boost//:asio",
    ],
)

cc_test(
    name = "network_test",
    srcs = ["test/network_test.cpp"],
    deps = [
        ":network_impl",
        "@googletest//:gtest_main",
    ],
)
