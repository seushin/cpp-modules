NAME := scavtrap

D_SRC := .
D_OBJ := ./obj
D_INC := .

SRC := main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ := $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
INC := -I$(D_INC)

LIB :=

CXX := clang++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror
RM := rm -f

# FORMAT
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
LF = \r\033[K
CRLF = \n$(LF)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)🚀 Build $(RESET)$@$(CRLF)"
	@$(CXX) $(CPPFLAGS) $(INC) $(LIB) -o $@ $(OBJ)

$(OBJ): | $(D_OBJ)

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(D_SRC)/%.cpp
	@printf "$(YELLOW)🔨 compiling:$(RESET) $<$(CRLF)"
	@$(CXX) $(CPPFLAGS) $(INC) -c $< -o $@

clean:
	@printf "$(YELLOW)🧹 Deleting all object from $(NAME)...$(RESET)$(CRLF)"
	@$(RM) -r $(D_OBJ)

fclean: clean
	@printf "$(YELLOW)🧹 Deleting all excutable from $(NAME)...$(RESET)$(CRLF)"
	@$(RM) $(NAME)

re: fclean all
