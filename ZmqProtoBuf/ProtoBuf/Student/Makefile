# See README.txt.

.PHONY: all cpp

all: cpp

cpp:    student_details_cpp
java:   student_details_java

clean:
	rm -f Student
	rm -f protoc_middleman Student.pb.cc Student.pb.h
	rm -f *.pyc

protoc_middleman: Student.proto
	protoc $$PROTO_PATH --cpp_out=. --java_out=. Student.proto
	@touch protoc_middleman

student_details_cpp: Student.cpp StudentReceive.cpp protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ -lzmq Student.cpp Student.pb.cc -o student_send_cpp `pkg-config --cflags --libs protobuf`
	c++ -lzmq StudentReceive.cpp Student.pb.cc -o student_recv_cpp `pkg-config --cflags --libs protobuf`

javac_middleman: StudentReceive.java protoc_middleman
	javac -cp $$CLASSPATH StudentReceive.java StudentProtos.java
	@touch javac_middleman

student_details_java: javac_middleman
	@echo "Writing shortcut script add_person_java..."
	@echo '#! /bin/sh' > student_details_java
	@echo 'java -classpath .:$$CLASSPATH StudentReceive "$$@"' >> student_details_java
	@chmod +x student_details_java

