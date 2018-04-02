package School;

import java.io.*;

public class StudentReceive {
    public static void main(String[] args) {
        ZMQ.Context context = ZMQ.context(1);
        ZMQ.Socket socket = context.socket(ZMQ.REP);
        socket.bind ("tcp://*:5555");
        byte[] request = socket.recv();

        StudentDetails p = StudentDetails.parseFrom(requestBytes)
    }
}
