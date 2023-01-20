NAME = Container

SRCS = main.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -D TEST=ft

OBJS = $(SRCS:.cpp=.o)

HEAD =	map/map.hpp \
			vector/vector.hpp \
			stacl/stack.hpp

INC = $(INCLUDES)

%.0: % .cpp $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@  

all : $(NAME)


$(NAME) :  $(OBJS) 
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			rm -f $(OBJS)
fclean : clean

re :		fclean all

.PHONY : all clean re fclean