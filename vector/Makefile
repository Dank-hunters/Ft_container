NAME = Container

FT_NAME = FT_Container

STD_NAME = STD_Container

FT_SRC = test_vector/mainft.cpp

STD_SRC = test_vector/mainstd.cpp

INCLUDE_PATH = .

HEADER = vector.hpp \
		../includes/random_acces_iterator.hpp \
		../includes/enable_if.hpp \
		../includes/compare.hpp \
		../includes/reverse_iterator.hpp 


FT_OBJ = $(FT_SRC:.cpp=.o)

STD_OBJ = $(STD_SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE_PATH)

%.o: %.cpp	$(HEADER)
	c++ $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJ)
	c++ $(CPPFLAGS) $(FT_OBJ) -o $(FT_NAME)

$(STD_NAME): $(STD_OBJ)
	c++ $(CPPFLAGS) $(STD_OBJ) -o $(STD_NAME)

clean:		
			rm -f $(STD_OBJ)
			rm -f $(FT_OBJ)
fclean : clean
			rm -f $(FT_NAME)
			rm -f $(STD_NAME)

re :		fclean all


.PHONY: all clean fclean re
