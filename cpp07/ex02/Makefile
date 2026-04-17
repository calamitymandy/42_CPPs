# Test leaks MACOS:
# leaks --atExit -- ./iter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = iter

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Colors
GREEN = \033[92m
YELLOW = \033[93m
RESET = \033[97m
RED = \033[91m
PURPLE = \033[95m

all: $(NAME)

%.o: %.cpp 
	@echo "$(YELLOW) Compiling...	$(RESET)$<"	
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(GREEN)✅ Program compiled successfully: $(NAME) $(RESET)\n"

clean:
	rm -f $(OBJS)
	@echo "$(RED)🧹 Object files removed $(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(PURPLE)🧼 Executable removed $(RESET)"

re: fclean all

.PHONY: all clean fclean re