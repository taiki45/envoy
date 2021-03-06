licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_test",
    "envoy_package",
    "envoy_select_google_grpc",
)

envoy_package()

envoy_cc_test(
    name = "async_client_impl_test",
    srcs = ["async_client_impl_test.cc"],
    deps = [
        "//source/common/common:enum_to_int",
        "//source/common/grpc:async_client_lib",
        "//source/common/grpc:common_lib",
        "//test/mocks/buffer:buffer_mocks",
        "//test/mocks/grpc:grpc_mocks",
        "//test/mocks/http:http_mocks",
        "//test/mocks/tracing:tracing_mocks",
        "//test/mocks/upstream:upstream_mocks",
        "//test/proto:helloworld_proto",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "async_client_manager_impl_test",
    srcs = ["async_client_manager_impl_test.cc"],
    deps = [
        "//source/common/grpc:async_client_manager_lib",
        "//test/mocks/stats:stats_mocks",
        "//test/mocks/thread_local:thread_local_mocks",
        "//test/mocks/upstream:upstream_mocks",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "codec_test",
    srcs = ["codec_test.cc"],
    deps = [
        "//source/common/buffer:buffer_lib",
        "//source/common/grpc:codec_lib",
        "//test/proto:helloworld_proto",
    ],
)

envoy_cc_test(
    name = "common_test",
    srcs = ["common_test.cc"],
    deps = [
        "//source/common/grpc:common_lib",
        "//source/common/http:headers_lib",
        "//test/mocks/upstream:upstream_mocks",
        "//test/proto:helloworld_proto",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "http1_bridge_filter_test",
    srcs = ["http1_bridge_filter_test.cc"],
    deps = [
        "//source/common/buffer:buffer_lib",
        "//source/common/grpc:http1_bridge_filter_lib",
        "//source/common/http:header_map_lib",
        "//test/mocks/http:http_mocks",
        "//test/mocks/upstream:upstream_mocks",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "google_grpc_test",
    srcs = envoy_select_google_grpc(["google_grpc_test.cc"]),
    external_deps = ["grpc"],
)

envoy_cc_test(
    name = "grpc_web_filter_test",
    srcs = ["grpc_web_filter_test.cc"],
    deps = [
        "//source/common/grpc:grpc_web_filter_lib",
        "//test/mocks/http:http_mocks",
        "//test/mocks/upstream:upstream_mocks",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "json_transcoder_filter_test",
    srcs = ["json_transcoder_filter_test.cc"],
    data = [
        "//test/proto:bookstore.proto",
        "//test/proto:bookstore_proto_descriptor",
    ],
    deps = [
        "//source/common/config:filter_json_lib",
        "//source/common/grpc:json_transcoder_filter_lib",
        "//test/mocks/http:http_mocks",
        "//test/mocks/upstream:upstream_mocks",
        "//test/proto:bookstore_proto",
        "//test/test_common:environment_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "transcoder_input_stream_test",
    srcs = ["transcoder_input_stream_test.cc"],
    deps = [
        "//source/common/buffer:buffer_lib",
        "//source/common/grpc:transcoder_input_stream_lib",
    ],
)
