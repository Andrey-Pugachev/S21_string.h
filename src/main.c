#include "s21_string.h"
#include <stdio.h>
//#include <limits.h>

int main() {

    //char str1[100];
    char str2[100];
    //char str3[100] = "Andrey"; 
    //s21_sprintf(str1, "|%o|\n", 1000000);
    sprintf(str2, "|% 12.12d|", 429496729);

    //printf("S21 %s\n", str1);
    printf("ORI %s\n", str2);     

    return 0;
}
