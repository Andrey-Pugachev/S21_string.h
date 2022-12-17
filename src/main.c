#include "s21_string.h"

int main() {
    char stringSrc[100] = "lll";
    char stringDest[100] = "helllo!";
    //s21_size_t n = 5;
    //char c = 'l';
    //scanf("%lu %c", &n, &c); 
    // fgets(stringDest, 99, stdin);
    // fgets(stringSrc, 99, stdin);
    printf("%p   s21_string.h\n", s21_strstr(stringDest, stringSrc));
    printf("%p   string.h\n", strstr(stringDest, stringSrc));
    return 0;
}
