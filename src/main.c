#include "s21_string.h"

int main() {
    
    char str[100] = {'\0'};
    printf("%s\n", str);
    s21_sprintf(str, "hello %+-#*.543Ld Ann", 44);
    printf("%s\n", str);

    return 0;
}
