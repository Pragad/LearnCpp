# For each .proto file, a proto_library target should be defined. This target
# is not bound to any particular language. Instead, it defines the dependency
# graph of the .proto files (i.e., proto imports) and serves as the provider
# of .proto source files to the protocol compiler.
#
# Remote repository "com_google_protobuf" must be defined to use this rule.
proto_library(
    name = "Student_proto",
    srcs = ["Student.proto"],
)

# The cc_proto_library rule generates C++ code for a proto_library rule. It
# must have exactly one proto_library dependency. If you want to use multiple
# proto_library targets, create a separate cc_proto_library target for each
# of them.
#
# Remote repository "com_google_protobuf_cc" must be defined to use this rule.
cc_proto_library(
    name = "Student_cc_proto",
    copts = ["-lzmq"],
    deps = [":Student_proto"],
)

# cc_library/cc_binary targets can depend on cc_proto_library targets.
cc_binary(
    name = "Student_cpp",
    copts = ["-lzmq"],
    srcs = ["Student.cpp"],
    deps = [":Student_cc_proto"],
)

cc_binary(
    name = "StudentReceive_cpp",
    copts = ["-lzmq"],
    srcs = ["StudentReceive.cpp"],
    deps = [":Student_cc_proto"],
)

# Similar to cc_proto_library but for Java.
#
# Remote repository "com_google_protobuf_java" must be defined to use this rule.
#java_proto_library(
#    name = "Student_java_proto",
#    deps = [":Student_cc_proto"],
#)
#
#java_binary(
#    name = "add_person_java",
#    srcs = ["AddPerson.java"],
#    main_class = "AddPerson",
#    deps = [":addressbook_java_proto"],
#)
#
#java_binary(
#    name = "list_people_java",
#    srcs = ["ListPeople.java"],
#    main_class = "ListPeople",
#    deps = [":addressbook_java_proto"],
#)

