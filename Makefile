NAME = a.out

CC = c++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

SRCS = *.cpp

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re
