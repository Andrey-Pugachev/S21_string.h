#include "s21_string.h"
#include <stdio.h>

int main() {

    //int n = 0;
    char str1[100];
    char str2[100];
    //char str3[100] = "Andrey"; 

    s21_sprintf(str1, "|%- 10.15i|", -54);
    sprintf(str2, "|%- 10.15i|", -54);
    printf("S21 %s\n", str1);
    printf("ORI %s\n", str2);     

    return 0;
}



    // s21_sprintf(str1, "|%c#%-7.4s#%15p#%n#%.4u|", 'F', str3, str3, &n, 3654);
    // sprintf(str2, "|%c#%-7.4s#%15p#%n#%.4u|", 'F', str3, str3, &n, 3654);
    // printf("S21 %s  %d\n", str1, n);
    // printf("ORI %s  %d\n", str2, n);




/*
ЗАДАЧИ:
1. Разобраться с флагами h и l (Зачем они нужны. Как реализовать. Как правитьно посылать числа в качестве аргументов в функцию)
*/