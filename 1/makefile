SRC = main.cpp
CXX = g++ -std=c++17
CXX_F = -Wall -Wextra
NAME = program

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXX_F) -o $@ $^

clean: 
	rm -fv $(NAME)
