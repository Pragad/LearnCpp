//
//  Hello World server in C++
//  Binds REP socket to tcp://*:5555
//  Expects "Hello" from client, replies with "World"
//
//  g++ -std=c++11 -lzmq PublisherZmq.cpp -o PublisherZmq
//
#include <iostream>
#include <string>
#include <unistd.h>
#include <zmq.hpp>

#include "Student.pb.h"

int main () {
    //  Prepare our context and socket
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    zmq::message_t request;

    //  Wait for next request from client
    socket.recv (&request);

    School::StudentDetails p = School::StudentDetails();
    p.ParseFromArray(request.data(), request.size());
    std::cout << "Name: " << p.name() << std::endl;
    std::cout << "Age: " << p.age() << std::endl;
    switch (p.gender())
    {
        case School::FEMALE:
            std::cout << "Gender: Female" << std::endl;
            break;
        case School::MALE:
            std::cout << "Gender: Male" << std::endl;
            break;
        default:
            std::cout << "Unknown Gender" << std::endl;
            break;
    }

    //  Send reply back to client
    /*
    zmq::message_t reply (5);
    memcpy (reply.data (), "world", 5);
    socket.send (reply);
    */

    return 0;
}


