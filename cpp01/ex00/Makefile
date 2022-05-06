NAME := ex00

D_SRC := .
D_OBJ := ./obj
D_INC := .

SRC := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ := $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
INC := -I$(D_INC)

CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror
RM := rm -f

ifeq ($(DEBUG), 1)
CXXFLAGS += -g -fsanitize=address
endif

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $(OBJ) $(LIB)

$(OBJ): | $(D_OBJ)

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(D_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(D_OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
