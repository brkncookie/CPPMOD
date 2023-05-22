CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
SRCS = Base.cpp utils.cpp main.cpp
OBJS = $(addprefix objs/, $(SRCS:.cpp=.o))
RM = rm -rf
NAME = identify

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

objs/%.o: %.cpp Base.hpp
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
