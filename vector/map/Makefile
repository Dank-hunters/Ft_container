NAME = Container

FT_NAME = FT_Container

STD_NAME = STD_Container

FT_SRC = test_map/mainft.cpp

STD_SRC = test_map/mainstd.cpp

INCLUDE_PATH = .

HEADER = map.hpp \
		node.hpp \
		tree.hpp \
		../includes/random_acces_iterator.hpp \
		../includes/iterator_traits.hpp \
		../includes/enable_if.hpp \
		../includes/compare.hpp \
		../includes/bidirectional_iterator.hpp \
		../includes/const_bidirectional_iterator.hpp \
		../includes/pair.hpp \
		../includes/reverse_iterator.hpp


FT_OBJ = $(FT_SRC:.cpp=.o)

STD_OBJ = $(STD_SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror  -I $(INCLUDE_PATH)

%.o: %.cpp	$(HEADER)
	c++ $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJ) $(HEADER)
	c++ $(CPPFLAGS) $(FT_OBJ) -o $(FT_NAME)

$(STD_NAME): $(STD_OBJ) $(HEADER)
	c++ $(CPPFLAGS) $(STD_OBJ) -o $(STD_NAME)

clean:		
			rm -f $(STD_OBJ)
			rm -f $(FT_OBJ)
fclean : clean
			rm -f $(FT_NAME)
			rm -f $(STD_NAME)

re :		fclean all


.PHONY: all clean fclean re
