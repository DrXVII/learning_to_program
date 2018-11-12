#include "server_ws.hpp"

using namespace std;

using Ws_server = SimpleWeb::SocketServer<SimpleWeb::WS>;

void replace_char(string* _str, const char _from, const char _to);

int main(int argc, char** argv) {
    constexpr unsigned short default_port {8080};
    unsigned short selected_port {0};
    //TODO test stoi(), catch exceptions
    if(argc == 2) { stoi(string(argv[1])); }

    // WebSocket (WS)-server at port 8080 using 1 thread
    Ws_server server;
    //TODO set port when calling this program
    server.config.port = 8080;

    // echo WebSocket endpoint
    auto &echo = server.endpoint["^/ws/?$"];

    echo.on_message =
        [](shared_ptr<Ws_server::Connection> connection,
        shared_ptr<Ws_server::Message> message)
    {
        string message_str = message->string();

        if((message->fin_rsv_opcode & 0x1) != 0x1) {
            cout << "Server: Received non-text data, closing connection"
                 << endl;
            //TODO check for correct error code
            connection->send_close(999, "non-text payload received");
            return;
        }

        cout << "Server: Message received: \"" << message_str << "\" "
             << "from " << connection.get() << endl;

        //replace all question marks with exclamation marks
        replace_char(&message_str, '?', '!');

        cout << "Server: Sending response \"" << message_str
             << "\" to " << connection.get() << endl;

        auto send_stream = make_shared<Ws_server::SendStream>();
        *send_stream << message_str;
        // connection->send is an asynchronous function
        connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
            if(ec) {
                cout << "Server: Error sending message. " <<
                        // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
                        "Error: " << ec << ", error message: " << ec.message() << endl;
            }
        });
    };

    echo.on_open = [](shared_ptr<Ws_server::Connection> connection) {
        cout << "Server: Opened connection " << connection.get() << endl;
    };

    // See RFC 6455 7.4.1. for status codes
    echo.on_close = [](shared_ptr<Ws_server::Connection> connection, int status, const string & /*reason*/) {
        cout << "Server: Closed connection " << connection.get() << " with status code " << status << endl;
    };

    // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
    echo.on_error = [](shared_ptr<Ws_server::Connection> connection, const SimpleWeb::error_code &ec) {
        cout << "Server: Error in connection " << connection.get() << ". "
                 << "Error: " << ec << ", error message: " << ec.message() << endl;
    };

    thread server_thread([&server]() {
        // Start WS-server
        server.start();
    });

    // Wait for server to start so that the client can connect
    //this_thread::sleep_for(chrono::seconds(1));

    server_thread.join();
}

void replace_char(string* _str, const char _from, const char _to)
{
    for(size_t i {0}; i < _str->size(); ++i) {
        if((*_str)[i] == _from) {(*_str)[i] = _to;}
    }
}
