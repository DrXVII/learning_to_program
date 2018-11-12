CXX_INCLUDE_DIRS = -I include/3rd_party -I include
CXX_LIBS = \
	-lboost_system \
	-lboost_thread \
	-lboost_coroutine \
	-lboost_context \
	-lssl \
	-lcrypto \
	-lboost_chrono \
	-lboost_date_time \
	-lboost_atomic \
	-lpthread
SERVER_NAME = server
CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):
	g++ -o $@ $(CXX_INCLUDE_DIRS) src/server.cpp $(CXX_LIBS)

$(CLIENT_NAME):
	g++ -o $@ $(CXX_INCLUDE_DIRS) src/client.cpp $(CXX_LIBS)

main:
	g++ -o test $(CXX_INCLUDE_DIRS) src/main.cpp $(CXX_LIBS)
