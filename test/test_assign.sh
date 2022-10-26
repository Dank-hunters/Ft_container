rm diff diff2
c++ -fsanitize=address -g3 -D TESTED_NAMESPACE=ft -D TESTED_TYPE=int main_assign.cpp  && ./a.out >> diff
c++ -fsanitize=address -g3 -D TESTED_NAMESPACE=std -D TESTED_TYPE=int main_assign.cpp  && ./a.out >> diff2
diff diff diff2

