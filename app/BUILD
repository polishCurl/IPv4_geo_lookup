cc_library(
    name = "app_interface",
    hdrs = [
        "iapp.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "app_factory",
    hdrs = [
        "app_factory.hpp",
    ],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
    deps = [
        ":app_interface",
        "//app/ipv4_geo_app",
    ],
)
