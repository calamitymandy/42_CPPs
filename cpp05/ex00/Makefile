# Test leaks MACOS:
# leaks --atExit -- ./polymorphism

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

# Colors
GREEN = \033[92m
YELLOW = \033[93m
WHITE = \033[97m
RED = \033[91m
PURPLE = \033[95m

all: $(NAME)

%.o: %.cpp 
	@echo "$(YELLOW) Compiling	$(WHITE)$<"	
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(GREEN)✅ Program compiled successfully: $(NAME) $(WHITE)\n"

clean:
	rm -f $(OBJS)
	@echo "$(RED)🧹 Object files removed $(WHITE)"

fclean: clean
	rm -f $(NAME)
	@echo "$(PURPLE)🧼 Executable removed $(WHITE)"

re: fclean all

.PHONY: all clean fclean re