//c++ std lib
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

//3rd party
#include "client_ws.hpp"

//TODO remove
using namespace std;

using Ws_client = SimpleWeb::SocketClient<SimpleWeb::WS>;

string make_address(int argc, char** argv);

int main(int argc, char** argv) {
    string address(make_address(argc, argv));
    if(address.size() == 0) {
        cout << "could not formulate address, please verify parameters" << endl
             << "the program will now terminate" << endl;
        return -1;
    }

    cout << "will connect to: \"" << address << "\"" << endl;

    Ws_client client(address);

    client.on_message =
        [](shared_ptr<Ws_client::Connection> connection,
           shared_ptr<Ws_client::Message> message)
    {
        cout << "Client: Message received: \"" << message->string() << "\"" << endl;

        cout << "Client: Sending close connection" << endl;
        connection->send_close(1000);
    };

    client.on_open = [](shared_ptr<Ws_client::Connection> connection) {
        cout << "Client: Opened connection" << endl;

        //remembering things we want to send
        vector<string> messages;
        //string message = "Hello? Is anybody listening? Am I alone?";
        messages.push_back(string("Hello? Is anybody listening? Am I alone?"));
        messages.push_back(string("?"));
        messages.push_back(string("???"));
        messages.push_back(string("!!!"));
        messages.push_back(string("? Woot? Yay!"));

        auto send_stream = make_shared<Ws_client::SendStream>();
        for(size_t i {0}; i < messages.size(); ++i) {
            cout << "Client: Sending message: \"" << messages[i]
                 << "\"" << endl;

            *send_stream << messages[i];
            connection->send(send_stream);
        }

        *send_stream << "before non_text";
        connection->send(send_stream);

        *send_stream << "non_text";
        //130 is the websocket opcode indicating binary data (single fragment)
        connection->send(send_stream, nullptr, 130);
    };

    client.on_close = [](shared_ptr<Ws_client::Connection> /*connection*/, int status, const string & /*reason*/) {
        cout << "Client: Closed connection with status code " << status << endl;
    };

    // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
    client.on_error = [](shared_ptr<Ws_client::Connection> /*connection*/, const SimpleWeb::error_code &ec) {
        cout << "Client: Error: " << ec << ", error message: " << ec.message() << endl;
    };

    client.start();
}

string make_address(int argc, char** argv)
{
    const string host("localhost:");
    const string path("/ws");
    const string default_port("8080");
    string selected_port(default_port);

    if(argc == 2) { selected_port = string(argv[1]); }
    else if(argc == 1) {
        cout << "no port setting provided, defaulting to " << selected_port
             << endl;
    }
    else {
        cout << "incorrect ammount of arguments provided" << endl;
        return string("");
    }

    return string(host + selected_port + path);
}
