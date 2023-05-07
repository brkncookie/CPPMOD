CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
SRCS = Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp AMateria.cpp main.cpp
OBJS = $(addprefix objs/, $(SRCS:.cpp=.o))
RM = rm -rf
NAME = materias

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

objs/%.o: %.cpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp AMateria.hpp
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
