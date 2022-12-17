main.o : main.c s21_string.h
	gcc -Wall -Werror -Wextra -c main.c -o main.o
s21_string.o : s21_string.c s21_string.h
	gcc -Wall -Werror -Wextra -c s21_string.c -o s21_string.o
s21_string : main.o s21_string.o
	gcc main.o s21_string.o -o s21_string
clean :
	rm s21_string *.o
