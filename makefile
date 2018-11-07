LD = g++ -std=c++17
CXX = g++ -std=c++17
CXX_F = -Wall -Wextra
INC_D = inc
SRC_D = src
OBJ_D = obj
CXX_INC = -I $(INC_D)
OBJ_ = main.o \
       drill_1_3.o \
       exercises_1_3.o \
       try_this.o
OBJ = $(patsubst %, $(OBJ_D)/%, $(OBJ_))
NAME = program

all: $(OBJ_D) $(NAME)

$(NAME): $(OBJ)
	@echo "LD \"$@\""
	@$(LD) -o $@ $^

$(OBJ_D)/%.o: $(SRC_D)/%.cpp
	@echo "CXX \"$@\""
	@$(CXX) $(CXX_F) $(CXX_INC) -c -o $@ $<

$(OBJ_D):
	@echo "mkdir \"$@\""
	@mkdir $@

#-------------------------------------------------------------------------------
clean: 
	rm -rfv $(OBJ_D)
	rm -fv $(NAME)
