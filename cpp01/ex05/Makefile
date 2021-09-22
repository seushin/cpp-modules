NAME := karen

D_SRC := .
D_OBJ := ./obj
D_INC := .

SRC := main.cpp Karen.cpp
OBJ := $(addprefix $(D_OBJ)/, $(SRC:.cpp=.o))
INC := -I$(D_INC)

LIB :=

CXX := clang++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror
RM := rm -f

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
LF = \033[1A\033[K

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)🚀 Build $(RESET)$@"
	@$(CXX) $(CPPFLAGS) $(INC) $(LIB) -o $@ $(OBJ)

$(OBJ): | $(D_OBJ)

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(D_SRC)/%.cpp
	@echo "$(LF)$(YELLOW)🔨 compiling:$(RESET) $<"
	@$(CXX) $(CPPFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Deleting all object from $(NAME)...$(RESET)"
	@$(RM) -r $(D_OBJ)

fclean: clean
	@echo "$(YELLOW)🧹 Deleting all excutable from $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean crlf all

crlf:
	@echo "\n$(LF)"

