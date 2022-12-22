rm diff diff2
c++ -fsanitize=address -g3 -std=c++98 -Wall -Wextra -Werror -D TESTED_NAMESPACE=ft -D TESTED_TYPE=std::string pop_push_erase.cpp  && ./a.out >> diff

c++ -fsanitize=address -g3 -D TESTED_NAMESPACE=std -D TESTED_TYPE=std::string pop_push_erase.cpp  && ./a.out >> diff2
diff diff diff2
rm -rf a.out.dSYM
c++ -std=c++98 -Wall -Wextra -Werror -D TESTED_NAMESPACE=ft -D TESTED_TYPE=std::string pop_push_erase.cpp

printf "############## leaks test ####################"
leaks -atExit -- ./a.out
rm a.out