//
//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back
//
//  g++ -std=c++11 -lzmq -o HelloClient HelloClientZmq.cpp
//
#include <zmq.hpp>
#include <string>
#include <iostream>

int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to hello world server…" << std::endl;
    std::string msg ="tcp://10.8.16.13:7201,start"; 
    //socket.connect (msg);
    socket.connect ("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        //zmq::message_t request (5);
        //memcpy (request.data (), "Hello", 5);
        zmq::message_t request (msg.size());
        memcpy (request.data (), msg.c_str(), msg.size());
        std::cout << "Sending Hello " << request_nbr << "…" << std::endl;
        socket.send (request);

        //  Get the reply.
        zmq::message_t reply;
        socket.recv (&reply);

        //std::cout << "Received World " << request_nbr << std::endl;
        //std::cout << "Received: " << zmq_msg_data(&reply) << std::endl;

        std::string msg_str(static_cast<char*>(reply.data()), reply.size());
        std::cout << "Received: " << msg_str << std::endl;
    }
    return 0;
}

