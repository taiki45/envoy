licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
    "envoy_proto_library",
)

envoy_package()

envoy_cc_library(
    name = "cds_api_lib",
    srcs = ["cds_api_impl.cc"],
    hdrs = ["cds_api_impl.h"],
    external_deps = ["envoy_cds"],
    deps = [
        ":cds_subscription_lib",
        "//include/envoy/config:subscription_interface",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/local_info:local_info_interface",
        "//source/common/common:cleanup_lib",
        "//source/common/common:logger_lib",
        "//source/common/config:resources_lib",
        "//source/common/config:subscription_factory_lib",
        "//source/common/config:utility_lib",
        "//source/common/protobuf:utility_lib",
    ],
)

envoy_cc_library(
    name = "cds_subscription_lib",
    srcs = ["cds_subscription.cc"],
    hdrs = ["cds_subscription.h"],
    external_deps = ["envoy_cds"],
    deps = [
        "//include/envoy/config:subscription_interface",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/json:json_object_interface",
        "//include/envoy/local_info:local_info_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:logger_lib",
        "//source/common/config:cds_json_lib",
        "//source/common/config:utility_lib",
        "//source/common/http:headers_lib",
        "//source/common/http:rest_api_fetcher_lib",
        "//source/common/json:config_schemas_lib",
        "//source/common/json:json_loader_lib",
    ],
)

envoy_cc_library(
    name = "cluster_manager_lib",
    srcs = ["cluster_manager_impl.cc"],
    hdrs = ["cluster_manager_impl.h"],
    external_deps = ["envoy_base"],
    deps = [
        ":cds_api_lib",
        ":load_balancer_lib",
        ":load_stats_reporter_lib",
        ":ring_hash_lb_lib",
        ":subset_lb_lib",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/http:codes_interface",
        "//include/envoy/local_info:local_info_interface",
        "//include/envoy/network:dns_interface",
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/ssl:context_manager_interface",
        "//include/envoy/thread_local:thread_local_interface",
        "//include/envoy/upstream:cluster_manager_interface",
        "//source/common/common:enum_to_int",
        "//source/common/common:utility_lib",
        "//source/common/config:cds_json_lib",
        "//source/common/config:grpc_mux_lib",
        "//source/common/config:utility_lib",
        "//source/common/filesystem:filesystem_lib",
        "//source/common/grpc:async_client_manager_lib",
        "//source/common/http:async_client_lib",
        "//source/common/http/http1:conn_pool_lib",
        "//source/common/http/http2:conn_pool_lib",
        "//source/common/network:resolver_lib",
        "//source/common/network:utility_lib",
        "//source/common/protobuf:utility_lib",
        "//source/common/router:shadow_writer_lib",
        "//source/common/upstream:upstream_lib",
    ],
)

envoy_cc_library(
    name = "health_checker_lib",
    srcs = ["health_checker_impl.cc"],
    hdrs = ["health_checker_impl.h"],
    external_deps = [
        "envoy_health_check",
        "grpc_health_proto",
    ],
    deps = [
        ":host_utility_lib",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/event:timer_interface",
        "//include/envoy/grpc:status",
        "//include/envoy/http:codec_interface",
        "//include/envoy/http:codes_interface",
        "//include/envoy/network:connection_interface",
        "//include/envoy/network:filter_interface",
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/stats:stats_interface",
        "//include/envoy/upstream:health_checker_interface",
        "//source/common/buffer:buffer_lib",
        "//source/common/buffer:zero_copy_input_stream_lib",
        "//source/common/common:empty_string",
        "//source/common/common:enum_to_int",
        "//source/common/common:hex_lib",
        "//source/common/common:logger_lib",
        "//source/common/common:utility_lib",
        "//source/common/grpc:codec_lib",
        "//source/common/grpc:common_lib",
        "//source/common/http:codec_client_lib",
        "//source/common/http:header_map_lib",
        "//source/common/http:headers_lib",
        "//source/common/http:utility_lib",
        "//source/common/network:filter_lib",
        "//source/common/protobuf:utility_lib",
        "//source/common/redis:conn_pool_lib",
    ],
)

envoy_cc_library(
    name = "host_utility_lib",
    srcs = ["host_utility.cc"],
    hdrs = ["host_utility.h"],
    deps = ["//include/envoy/upstream:upstream_interface"],
)

envoy_cc_library(
    name = "load_balancer_lib",
    srcs = ["load_balancer_impl.cc"],
    hdrs = ["load_balancer_impl.h"],
    deps = [
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/stats:stats_interface",
        "//include/envoy/upstream:load_balancer_interface",
        "//include/envoy/upstream:upstream_interface",
        "//source/common/common:assert_lib",
    ],
)

envoy_cc_library(
    name = "load_stats_reporter_lib",
    srcs = ["load_stats_reporter.cc"],
    hdrs = ["load_stats_reporter.h"],
    external_deps = ["envoy_eds"],
    deps = [
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/stats:stats_macros",
        "//include/envoy/upstream:cluster_manager_interface",
        "//source/common/common:logger_lib",
        "//source/common/grpc:async_client_lib",
    ],
)

envoy_cc_library(
    name = "logical_dns_cluster_lib",
    srcs = ["logical_dns_cluster.cc"],
    hdrs = ["logical_dns_cluster.h"],
    deps = [
        ":upstream_includes",
        "//include/envoy/thread_local:thread_local_interface",
        "//source/common/common:empty_string",
        "//source/common/config:utility_lib",
        "//source/common/network:address_lib",
        "//source/common/network:utility_lib",
        "//source/common/protobuf",
        "//source/common/protobuf:utility_lib",
    ],
)

envoy_cc_library(
    name = "original_dst_cluster_lib",
    srcs = ["original_dst_cluster.cc"],
    hdrs = ["original_dst_cluster.h"],
    deps = [
        ":upstream_includes",
        "//source/common/common:empty_string",
        "//source/common/network:address_lib",
        "//source/common/network:utility_lib",
    ],
)

envoy_cc_library(
    name = "outlier_detection_lib",
    srcs = ["outlier_detection_impl.cc"],
    hdrs = ["outlier_detection_impl.h"],
    external_deps = ["envoy_cds"],
    deps = [
        "//include/envoy/access_log:access_log_interface",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/event:timer_interface",
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/upstream:outlier_detection_interface",
        "//include/envoy/upstream:upstream_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:utility_lib",
        "//source/common/http:codes_lib",
        "//source/common/protobuf",
    ],
)

envoy_cc_library(
    name = "resource_manager_lib",
    hdrs = ["resource_manager_impl.h"],
    deps = [
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/upstream:resource_manager_interface",
        "//source/common/common:assert_lib",
    ],
)

envoy_cc_library(
    name = "ring_hash_lb_lib",
    srcs = ["ring_hash_lb.cc"],
    hdrs = ["ring_hash_lb.h"],
    external_deps = [
        "abseil_strings",
    ],
    deps = [
        ":load_balancer_lib",
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/upstream:load_balancer_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:logger_lib",
    ],
)

envoy_cc_library(
    name = "eds_lib",
    srcs = ["eds.cc"],
    hdrs = ["eds.h"],
    external_deps = [
        "envoy_base",
        "envoy_eds",
    ],
    deps = [
        ":sds_subscription_lib",
        ":upstream_includes",
        "//include/envoy/config:grpc_mux_interface",
        "//include/envoy/config:subscription_interface",
        "//include/envoy/local_info:local_info_interface",
        "//source/common/config:metadata_lib",
        "//source/common/config:subscription_factory_lib",
        "//source/common/config:utility_lib",
        "//source/common/config:well_known_names",
        "//source/common/network:address_lib",
        "//source/common/network:resolver_lib",
        "//source/common/network:utility_lib",
        "//source/common/protobuf:utility_lib",
    ],
)

envoy_cc_library(
    name = "sds_subscription_lib",
    srcs = ["sds_subscription.cc"],
    hdrs = ["sds_subscription.h"],
    external_deps = [
        "envoy_base",
        "envoy_eds",
    ],
    deps = [
        "//include/envoy/config:subscription_interface",
        "//source/common/common:assert_lib",
        "//source/common/config:metadata_lib",
        "//source/common/config:utility_lib",
        "//source/common/config:well_known_names",
        "//source/common/http:headers_lib",
        "//source/common/http:rest_api_fetcher_lib",
        "//source/common/json:config_schemas_lib",
        "//source/common/json:json_loader_lib",
        "//source/common/protobuf",
        "//source/common/router:router_lib",
    ],
)

envoy_cc_library(
    name = "subset_lb_lib",
    srcs = ["subset_lb.cc"],
    hdrs = ["subset_lb.h"],
    deps = [
        ":load_balancer_lib",
        ":ring_hash_lb_lib",
        ":upstream_lib",
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/upstream:load_balancer_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:logger_lib",
        "//source/common/config:metadata_lib",
        "//source/common/config:well_known_names",
        "//source/common/protobuf",
        "//source/common/protobuf:utility_lib",
    ],
)

envoy_cc_library(
    name = "upstream_lib",
    srcs = ["upstream_impl.cc"],
    external_deps = ["envoy_base"],
    deps = [
        ":eds_lib",
        ":health_checker_lib",
        ":logical_dns_cluster_lib",
        ":original_dst_cluster_lib",
        ":upstream_includes",
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/event:timer_interface",
        "//include/envoy/network:dns_interface",
        "//include/envoy/ssl:context_interface",
        "//include/envoy/upstream:health_checker_interface",
        "//source/common/common:enum_to_int",
        "//source/common/common:utility_lib",
        "//source/common/config:protocol_json_lib",
        "//source/common/config:tls_context_json_lib",
        "//source/common/http:utility_lib",
        "//source/common/network:address_lib",
        "//source/common/network:resolver_lib",
        "//source/common/network:utility_lib",
        "//source/common/protobuf",
        "//source/common/protobuf:utility_lib",
        "//source/common/ssl:connection_lib",
        "//source/common/ssl:context_config_lib",
    ],
)

envoy_cc_library(
    name = "upstream_includes",
    hdrs = ["upstream_impl.h"],
    external_deps = ["envoy_base"],
    deps = [
        ":load_balancer_lib",
        ":outlier_detection_lib",
        ":resource_manager_lib",
        "//include/envoy/event:timer_interface",
        "//include/envoy/local_info:local_info_interface",
        "//include/envoy/network:dns_interface",
        "//include/envoy/runtime:runtime_interface",
        "//include/envoy/server:transport_socket_config_interface",
        "//include/envoy/ssl:context_manager_interface",
        "//include/envoy/thread_local:thread_local_interface",
        "//include/envoy/upstream:cluster_manager_interface",
        "//include/envoy/upstream:health_checker_interface",
        "//include/envoy/upstream:load_balancer_interface",
        "//include/envoy/upstream:upstream_interface",
        "//source/common/common:callback_impl_lib",
        "//source/common/common:enum_to_int",
        "//source/common/common:logger_lib",
        "//source/common/config:metadata_lib",
        "//source/common/config:well_known_names",
        "//source/common/stats:stats_lib",
    ],
)
