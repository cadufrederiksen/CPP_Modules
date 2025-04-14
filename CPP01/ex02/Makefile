NAME = brain
GCC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
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
	
re: fclean all

.PHONY: clean all re fclean