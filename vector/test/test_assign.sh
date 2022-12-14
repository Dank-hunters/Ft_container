rm diff diff2
c++ -fsanitize=address -g3  -Wall -Wextra -Werror -D TESTED_NAMESPACE=ft -D TESTED_TYPE=int assign_test.cpp  && ./a.out >> diff
c++ -fsanitize=address -g3 -D TESTED_NAMESPACE=std -D TESTED_TYPE=int assign_test.cpp  && ./a.out >> diff2
diff diff diff2

rm -rf a.out.dSYM
c++  -Wall -Wextra -Werror -D TESTED_NAMESPACE=ft -D TESTED_TYPE=int assign_test.cpp

printf "############## leaks test ####################"
leaks -atExit -- ./a.out
rm a.out