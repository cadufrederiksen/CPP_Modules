NAME = dream
GCC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp Account.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAG) -o $(NAME) $^

%.o: %.cpp
	$(GCC) $(FLAG) -c $< -o $@

clean: 
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: clean all

.PHONY: clean all re fclean