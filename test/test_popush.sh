rm diff diff2
c++ -fsanitize=address -g3 -D TESTED_NAMESPACE=ft -D TESTED_TYPE=std::string main_pop_push.cpp  && ./a.out >> diff
c++ -fsanitize=address -g3 -D TESTED_NAMESPACE=std -D TESTED_TYPE=std::string main_pop_push.cpp  && ./a.out >> diff2
diff diff diff2

