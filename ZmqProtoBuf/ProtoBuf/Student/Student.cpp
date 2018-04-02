#include <iostream>
#include <string>
#include <zmq.hpp>

#include "Student.pb.h"

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    School::StudentDetails studentDetails;
    studentDetails.set_name("Sam");
    studentDetails.set_age(28);
    studentDetails.set_gender(School::MALE);

    std::cout << "Student Name: " << studentDetails.name() << std::endl;
    std::cout << "Student Age: " << studentDetails.age() << std::endl;
    switch (studentDetails.gender())
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

    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    // Connect to video recording service
    socket.connect ("tcp://localhost:5555");

    // Construct a string from the protobuf message
    std::string msg;
    studentDetails.SerializeToString(&msg);
    zmq::message_t request (msg.size());
    memcpy(request.data(), msg.c_str(), msg.size());

    // Send the zmq message over the socket
    std::cout << "Sending start recording message..." << std::endl;
    std::cout << "REQ: " << request << std::endl;
    socket.send (request);

    //  Get the reply.
    /*
    zmq::message_t reply;
    socket.recv (&reply);
    School::StudentDetails recordResponse = School::StudentDetails();
    recordResponse.ParseFromArray(reply.data(), reply.size());
    std::cout << "Student name: " << recordResponse.name() << std::endl;
    */

    // Print the reply
    /*
    std::string msg_str(static_cast<char*>(reply.data()), reply.size());
    std::cout << "Received: " << msg_str << std::endl;
    */

    // Optional:  Delete all global objects allocated by libprotobuf
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
