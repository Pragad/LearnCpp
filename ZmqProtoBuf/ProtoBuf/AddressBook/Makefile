# See README.txt.

.PHONY: all cpp

all: cpp

cpp:    add_person_cpp

clean:
	rm -f add_person_cpp
	rm -f protoc_middleman addressbook.pb.cc addressbook.pb.h addressbook_pb2.py
	rm -f *.pyc

protoc_middleman: addressbook.proto
	protoc $$PROTO_PATH --cpp_out=. addressbook.proto
	@touch protoc_middleman

add_person_cpp: add_person.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ add_person.cc addressbook.pb.cc -o add_person_cpp `pkg-config --cflags --libs protobuf`
