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



int s21_itoa(long long num, char** str) { //Надо доработать обработку отрицательного числа.
    int count = 0;
    int numberOfdigits = intNumberLengthCounter(num);
    numberOfdigits++;
    char number[numberOfdigits];
    for (int i = 0; i < numberOfdigits; i++)
        number[i] = '\0';
    int i = 0;
    while (num > 0) {
        number[i] = (num % 10);
        num = num / 10;
        i++;
    }
    while (i > 0) {
        i--;
        **str = ('0' + number[i]);
        *str = *str +1;
        count++;
    }
    return count;
}



void writeFromFormatString(char** str, const char** format) {
    **str = **format;
    *str = *str +1;
    *format = *format + 1;
}



void formatModesParser(const char** format, formatModes* flags, va_list* argumentPointer) {   
    while (**format == '-' || **format == '+' || **format == ' ' || **format == '#' || **format == '0') {
        if (**format == '-') {
            flags->minus = 1;
        } else if (**format == '+') {
            flags->plus = 1;
        } else if (**format == ' ') {
            flags->space = 1;
        } else if (**format == '0') {
            flags->zero = 1;
        } else if (**format == '#') {
            flags->lattice = 1;
        }
        *format = *format + 1;
    }
    while (**format == '*' || ('0' <= **format && **format <= '9')) {
        if (**format == '*') {
            flags->width = va_arg(*argumentPointer, int);
            *format = *format + 1;
            break;
        }
        char* strWidth = (char*)calloc(350, sizeof(char));
        for (int i = 0; '0' <= **format && **format <= '9'; i++) {
            *(strWidth + i) = **format;
            *format = *format + 1;
        }
        flags->width = s21_atoi(strWidth);
        free(strWidth);
    }
    if (**format == '.') {
        flags->accuracyPoint = 1;
        *format = *format + 1;
        while (**format == '*' || ('0' <= **format && **format <= '9')) {
            if (**format == '*') {
                flags->accuracy = va_arg(*argumentPointer, int);
                *format = *format + 1;
                break;
            }
            char* strAccuracy = (char*)calloc(350, sizeof(char));
            for (int i = 0; '0' <= **format && **format <= '9'; i++) {
                *(strAccuracy + i) = **format;
                *format = *format + 1;
            }
            flags->accuracy = s21_atoi(strAccuracy);
            free(strAccuracy);
        }
    }
    if (**format == 'h' || **format == 'l' || **format == 'L') {
        flags->len = **format;
        *format = *format + 1;
    }
    flags->placeHolder = **format;
    *format = *format + 1;
}



int intNumberLengthCounter(long long numberFromArgument){
    int count = 0;
    if (numberFromArgument < 0) {
        numberFromArgument = -numberFromArgument;
        count++;
    }
    for (; numberFromArgument > 9; numberFromArgument = numberFromArgument / 10)
        count++;
    count++;
    return count;
}



void writeFromArgument(char** str, formatModes* flags, va_list* argumentPointer) {
    if (flags->placeHolder == 'c') {
        **str = (char)va_arg(*argumentPointer, int);
        *str = *str + 1;
    } else if (flags->placeHolder == 'd' || flags->placeHolder == 'i') {
        long long numberFromArgument = va_arg(*argumentPointer, long long);
        int lengthOfNumber = intNumberLengthCounter(numberFromArgument);
        if (flags->space)
            flags->plus = 0;
        if (flags->accuracyPoint)
            flags->zero = 0;
        if (flags->minus) {
            if (numberFromArgument < 0) {
                **str = '-';
                *str = *str + 1;
                lengthOfNumber--;
            } else {
                if (flags->plus) {
                    **str = '+';
                    *str = *str + 1;
                }
                if (flags->space) {
                    **str = ' ';
                    *str = *str + 1;
                }
            }
            if (flags->accuracy > lengthOfNumber) {
                for (int i = 0; i < (flags->accuracy - lengthOfNumber); i++) {
                    **str = '0';
                    *str = *str + 1;
                }
            }
            long long tmpNumberFromArgument = 0;
            if (numberFromArgument < 0)
                tmpNumberFromArgument = -numberFromArgument;
            else
                tmpNumberFromArgument = numberFromArgument;
            s21_itoa(tmpNumberFromArgument, str);
            if (flags->accuracy >= lengthOfNumber) {
                if (flags->width > flags->accuracy) {
                    for (int i = 0; i < (flags->width - flags->accuracy); i++) {
                        **str = ' ';
                        *str = *str + 1;
                    }
                }    
            } else {
                if (flags->width > lengthOfNumber) {
                    for (int i = 0; i < (flags->width - lengthOfNumber); i++) {
                        **str = ' ';
                        *str = *str + 1;                    
                    }
                }
            }    
        } else {
            if (flags->accuracy > lengthOfNumber) {
                if (flags->width > flags->accuracy) {
                    if (numberFromArgument < 0) {
                        for (int i = 0; i < (flags->width - (flags->accuracy + 1)); i++) {
                            **str = ' ';
                            *str = *str + 1;
                        }
                        **str = '-';
                        *str = *str + 1;
                    } else {
                        if (flags->space) {
                            for (int i = 0; i < (flags->width - (flags->accuracy)); i++) {
                                **str = ' ';
                                *str = *str + 1;
                            }    
                        }
                        if (flags->plus) {
                            for (int i = 0; i < (flags->width - (flags->accuracy + 1)); i++) {
                                **str = ' ';
                                *str = *str + 1;
                            }
                            **str = '+';
                            *str = *str + 1;
                        }
                    }
                }
                
            }
        }


    }
}



int s21_sprintf(char* str, const char* format, ...) {
    va_list argumentPointer;
    va_start(argumentPointer, format);
    while (*format != '\0') {
        if (*format != '%') {
            writeFromFormatString(&str, &format);
        } else {
            formatModes flags = {0};
            format++;
            if (*format == '%')
                writeFromFormatString(&str, &format);
            else
                formatModesParser(&format, &flags, &argumentPointer);
            writeFromArgument(&str, &flags, &argumentPointer);



        }
        va_end(argumentPointer);
    }
    return 0;
}


//1. Отаботать случай ноля в качестве целочисленного значения.
//================================================================================================================================================================
