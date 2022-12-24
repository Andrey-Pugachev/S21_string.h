#include "s21_string.h"

s21_size_t s21_strlen(const char* str) {
    s21_size_t size = 0;
    for (; *str != '\0'; str++)
        size++;
    return size;
}

char* s21_strcpy(char* dest, const char* src) {
    if (dest == s21_NULL)
        return s21_NULL;
    char* p = dest;    
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return p;
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
    if (dest == NULL)
        return NULL;
    char* p = dest;    
    while (*src != '\0' && n != 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return p;
}

char* s21_strcat(char* dest, const char* src) {
    if (dest == NULL)
        return NULL;
    char* p = dest;
    while (*dest != '\0')
        dest++;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return p;
}

char* s21_strncat(char* dest, const char* src, s21_size_t n) {
    if (dest == NULL)
        return NULL;
    char* p = dest;
    while (*dest != '\0')
        dest++;
    while (*src != '\0' && n != 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return p;
}

int s21_strcmp(const char* str1, const char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
    while (*str1 == *str2 && n > 1) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
        n--;
    }
    return *str1 - *str2;
}

char* s21_strchr(const char* str, int c) {
    while (*str != '\0') {
        if (*str == c)
            return (char*)str;
        str++;
    }
    return s21_NULL;
}

char* s21_strrchr(const char* str, int c) {
    char* p = s21_NULL;
    while (*str != '\0') {
        if (*str == c)
            p = (char*)str;
        str++;
    }
    return p;
}

s21_size_t s21_strspn(const char* str1, const char* str2) {
    s21_size_t count = 0;
    char bigFlag = 0;
    while (*str1 != '\0') {
        const char* tmpStr2 = str2;
        char flag = 0;
        while (*tmpStr2 != '\0') {
            if (*str1 == *tmpStr2) {
                flag = 1;
                break;
            }
            tmpStr2++;
        }
        if (flag) {
            count++;
            bigFlag = 0;
        } else
            bigFlag = 1;
        str1++;
        if (!flag && !count)
            return count;
        if (bigFlag && count)
            return count;
    }
    return count;
}

s21_size_t s21_strcspn(const char* str1, const char* str2) {
    s21_size_t count = 0;
    while (*str1 != '\0') {
        const char* str2Tmp = str2;
        while (*str2Tmp != '\0') {
            if (*str1 == *str2Tmp)
                return count;
            str2Tmp++;
        }
        count++;
        str1++;
    }
    return count;
}

char* s21_strpbrk(const char* str1, const char* str2) {
    while (*str1 != '\0') {
        const char* str2Tmp = str2;
        while (*str2Tmp != '\0') {
            if (*str1 == *str2Tmp)
                return (char*)str1;
            str2Tmp++;
        }
        str1++;
    }
    return s21_NULL;
}

char* s21_strstr(const char* haystack, const char* needle) {
    if (!(*needle))
        return (char*)haystack;
    while (*haystack != '\0') {
        char flag = 0;
        if (*haystack == *needle) {
            char* needleTmp = (char*)needle;
            char* haystackTmp = (char*)haystack;
            while (*needleTmp != '\0') {
                if (*haystackTmp == *needleTmp) {
                    flag = 1;
                    haystackTmp++;
                    needleTmp++;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                return (char*)haystack;
        }
        haystack++;
    }
    return s21_NULL;
}

char* s21_strtok(char* str, const char* delim) {
    static char *separatedString = s21_NULL;
    int flag = 0;
    if (str != s21_NULL)
        separatedString = str;
    if (separatedString) {
        str = separatedString + s21_strspn(separatedString, delim);
        separatedString = str + s21_strcspn(str, delim);
        if (separatedString == str) {
            separatedString = s21_NULL;
            flag = 1;
        } else
        separatedString = *separatedString ? *separatedString = 0, separatedString + 1 : 0;
    }
    return flag == 1 ? s21_NULL : str;
}

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
    char* charDest = (char*)dest;
    char* charSrc = (char*)src;
    for (s21_size_t i = 0; i < n; i++)
        *(charDest + i) = *(charSrc + i);
    return dest;
}

// void* s21_memmove(void* dest, const void* src, s21_size_t n) { //Узнать почему каллочим место под n байт а не n+1 куда денем '\0'?????? и в чем разница между ней и memcpy()
//     char *tmpString;
//     tmpString = (char *)calloc(n, sizeof(char));
//     s21_memcpy(tmpString, src, n);
//     s21_memcpy(dest, tmpString, n);
//     free(tmtmpStringp);
//     return dest;
// }

void* s21_memset(void* str, int c, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++)
        *((char *)str + i) = c;
  return str;
}

void* s21_memchr(const void* str, int c, s21_size_t n) { //Как измерить длинну строки ыек6 что бы не выйти за еъё приделы если n будет больше её длинны? 
    for (s21_size_t i = 0; i < n; i++)
        if (*((char*)str + i) == c)
            return (void*)(str + i);
    return s21_NULL;
}

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) { //Что если n больше самой строки, не выйдем ли мы за пределы строки и не будет ли segfault?
    int result = 0;
    char *str1Tmp = (char *)str1;
    char *str2Tmp = (char *)str2;
    for (s21_size_t i = 0; i < n; i++)
        if (*(str1Tmp + i) != *(str2Tmp + i)) {
            result = *(str1Tmp + i) - *(str2Tmp + i);
            break;
        }
    return result;
}

char* s21_strerror(int errnum) {
    const char* errorList[] = ERRORS;
    static char array[300] = {'\0'};
    if (errnum >= 0 && errnum <= 106)
        return (char*)errorList[errnum];
    else {
        sprintf(array, "Unknown error: %d", errnum);
        return array;
    }    
}

//==========================================================================================all additional funcs for sprintf()====================================
int s21_atoi(char *str) {
    int num = 0;
    int isMinus = 0;
    if (*str == '-') {
        isMinus = 1;
        str++;
    }
    for (; *str >= '0' && *str <= '9'; str++)
        num = (num * 10) + (*str - '0');
    return (isMinus) ? -num : num;
}

// int formatModesParser(const char** format, formatModes* flags) {
   
// }

int s21_sprintf(char* str, const char* format, ...) {

    va_list argumentPointer;
    va_start(argumentPointer, format);

    while (*format != '\0') {
        if (*format != '%') {
            *str = *format;
            str++;
            format++;
        } else {
            formatModes flags = {0};
            format++;
            //Считываем флаги (+,-,0, ,#)   
            while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' || *format == '0') {
                if (*format == '-') {
                    flags.minus = 1;
                } else if (*format == '+') {
                    flags.plus = 1;
                } else if (*format == ' ') {
                    flags.space = 1;
                } else if (*format == '0') {
                    flags.zero = 1;
                } else if (*format == '#') {
                    flags.lattice = 1;
                }
                format++;
            }
            //Считываем ширину выделяемого иоля (число, *)
            while (*format == '*' || ('0' <= *format && *format <= '9')) {
                if (*format == '*') {
                    flags.width = va_arg(argumentPointer, int);
                    format++;
                    break;
                }
                char* strWidth = (char*)calloc(350, sizeof(char));
                for (int i = 0; '0' <= *format && *format <= '9'; i++) {
                    *(strWidth + i) = *format;
                    format++;
                }
                flags.width = s21_atoi(strWidth);
                free(strWidth);
            }
            //Считываем точность (.число, .*)
            if (*format == '.') {
                format++;
                while (*format == '*' || ('0' <= *format && *format <= '9')) {
                    if (*format == '*') {
                        flags.accuracy = va_arg(argumentPointer, int);
                        format++;
                        break;
                    }
                    char* strAccuracy = (char*)calloc(350, sizeof(char));
                    for (int i = 0; '0' <= *format && *format <= '9'; i++) {
                        *(strAccuracy + i) = *format;
                        format++;
                    }
                    flags.accuracy = s21_atoi(strAccuracy);
                    free(strAccuracy);
                }
            }
            //Считываем длинну (h,l,L)
            if (*format == 'h' || *format == 'l' || *format == 'L') {
                flags.len = *format;
                format++;
            }



            printf("minus - %d\n", flags.minus);
            printf("plus - %d\n", flags.plus);
            printf("space - %d\n", flags.space);
            printf("lattice - %d\n", flags.lattice);
            printf("zero - %d\n", flags.zero);
            printf("len - %c\n", flags.len);
            puts("");
            printf("width - %d\n", flags.width);
            printf("accuracy - %d\n", flags.accuracy);
        }
        va_end(argumentPointer);
    }
    return 0;
}
//================================================================================================================================================================
