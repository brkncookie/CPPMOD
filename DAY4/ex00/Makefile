CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
SRCS = Dog.cpp Cat.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp main.cpp
OBJS = $(addprefix objs/, $(SRCS:.cpp=.o))
RM = rm -rf
NAME = thezoo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

objs/%.o: %.cpp Dog.hpp Cat.hpp Animal.hpp WrongCat.hpp WrongAnimal.hpp
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
