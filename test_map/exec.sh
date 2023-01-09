rm test2 test                                                                         
c++ test_insert.cpp -D TESTED_NAMESPACE=ft -fsanitize=address -g3 && ./a.out >> test2 
c++ test_insert.cpp -D TESTED_NAMESPACE=std -fsanitize=address -g3 && ./a.out >> test 
diff test test2   