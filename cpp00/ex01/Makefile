# Name of the final executable
NAME = phonebook

# Compiler and flags (C++98 standard, with warnings enabled)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and object files
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target: compile the program
all: $(NAME)

# Link all object files into the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Clean and rebuild
re: fclean all
