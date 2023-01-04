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

//================================================================================================================================================================
//==========================================================================================all additional funcs for sprintf()====================================

int s21_sprintf(char* str, const char* format, ...) {
    int countOfPrinted = 0;
    va_list argumentPointer;
    va_start(argumentPointer, format);
    while (*format != '\0') {
        if (*format != '%')
            writeFromFormatString(&str, &format, &countOfPrinted);
        else {
            formatModes flags = {0};
            format++;
            if (*format == '%')
                writeFromFormatString(&str, &format, &countOfPrinted);
            else {
                formatModesParser(&format, &flags, &argumentPointer);
                writeFromArgument(&str, &flags, &argumentPointer, &countOfPrinted);
            }
        }
        va_end(argumentPointer);
    }
    return countOfPrinted;
}

int s21_atoi(char *str) { //Переводит строку цыфровых символов в число
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

int s21_numToStr(long long num, char* str, int numSys, int saveMinus, int* countOfPrinted, int isUppercaseX) { //Перевод целого числа заданной системы исчисления в строку
    int count = 0;
    int arrLen = 0;
    arrLen = (s21_intNumLen(num, numSys) + 1);
    char digArr[arrLen];
    for (int i = 0; i < arrLen; i++)
        digArr[i] = '\0';
    char* strTmp = str;
    if (num < 0) {
        num = -num;
        if (saveMinus) {
            *strTmp = '-';
            *countOfPrinted = *countOfPrinted + 1;
            strTmp++;
            *strTmp = '\0';
            count++;
        } 
    }
    if (num == 0) {
        *strTmp = '0';
        *countOfPrinted = *countOfPrinted + 1;
        strTmp++;
        *strTmp = '\0';
        count++;
    }
    int i = 0;
    int digit16 = 0;
    while (num > 0) {
        digit16 = num % numSys;
        if (digit16 < 10)
            digArr[i] = '0' + digit16;
        else
            digArr[i] = ((isUppercaseX) ? 'A' : 'a') + (digit16 - 10);
        num = num / numSys;
        i++;
    }
    while (i > 0) {
        i--;
        *strTmp = digArr[i];
        *countOfPrinted = *countOfPrinted + 1;
        strTmp++;
        *strTmp = '\0';
        count++;
    }
    return count;
}

int s21_intNumLen(long long num, int numSys) { //Подсчёт длинны целого числа, заданной системы исчисления.
    int count = 0;
    if (num < 0)
        num = - num;
    for (; num > (numSys - 1); num = num / numSys) {
        count++;
    }
    count++;
    return count;
}

void writeFromFormatString(char** str, const char** format, int* countOfPrinted) { //Запись из форматной строки
    **str = **format;
    *countOfPrinted = *countOfPrinted + 1;
    *str = *str +1;
    **str = '\0';
    *format = *format + 1;
}

void formatModesParser(const char** format, formatModes* flags, va_list* argumentPointer) { //Парсинг спецыфикатора формата
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

void writeFromArgument(char** str, formatModes* flags, va_list* argumentPointer, int* countOfPrinted) {
//СПЕЦЫФИКАТОР ФОРМАТА  %C
    if (flags->placeHolder == 'c') {
        char c = (char)va_arg(*argumentPointer, int);
        int spaces = 0;
        if (flags->width > 1)
            spaces = flags->width - 1;
        if (flags->minus) {
            **str = c;
            *countOfPrinted = *countOfPrinted + 1;
            *str = *str + 1;
            **str = '\0';
            for (int i = 0; i < spaces; i++) {
                **str = ' ';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
        } else {
            for (int i = 0; i < spaces; i++) {
                **str = ' ';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
            **str = c;
            *countOfPrinted = *countOfPrinted + 1;
            *str = *str + 1;
            **str = '\0';
        }
//СПЕЦЫФИКАТОР ФОРМАТА  %S
    } else if (flags->placeHolder == 's') {
        char* argString = va_arg(*argumentPointer, char*);
        int strLength = (int)s21_strlen(argString);
        int charCount = (flags->accuracy < strLength && flags->accuracyPoint) ? flags->accuracy : strLength;
        if (flags->minus) {
            for (int i = 0; i < charCount; i++) {
                **str = *argString;
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                argString++;
                **str = '\0';
            }
            if (flags->width > charCount) {
                for (int i = 0; i < (flags->width - charCount); i++) {
                    **str = ' ';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                }
            }
        } else {
            if (flags->width > charCount) {
                for (int i = 0; i < (flags->width - charCount); i++) {
                    **str = ' ';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                }
            }
            for (int i = 0; i < charCount; i++) {
                **str = *argString;
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                argString++;
                **str = '\0';
            }
        }
//СПЕЦЫФИКАТОР ФОРМАТА  %P
    } else if (flags->placeHolder == 'p') {
        long long pointer = va_arg(*argumentPointer, long long);
        int pointJump = 0;
        if (flags->minus) {
            **str = '0';
            *str = *str + 1;
            **str = 'x';
            *countOfPrinted = *countOfPrinted + 2;
            *str = *str + 1;
            **str = '\0';
            pointJump = s21_numToStr(pointer ,*str, 16, 0, countOfPrinted, 0);
            *str = *str + pointJump;
            if (flags->width > 11) {
                for (int i = 0; i < (flags->width - (s21_intNumLen(pointer, 16) + 2)); i++) {
                    **str = ' ';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                }
            }
        } else {
            if (flags->width > 11) {
                for (int i = 0; i < (flags->width - (s21_intNumLen(pointer, 16) + 2)); i++) {
                    **str = ' ';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                }
            }
            **str = '0';
            *str = *str + 1;
            **str = 'x';
            *countOfPrinted = *countOfPrinted + 2;
            *str = *str + 1;
            **str = '\0';
            pointJump = s21_numToStr(pointer , *str, 16, 0, countOfPrinted, 0);
            *str = *str + pointJump;
        }
//СПЕЦЫФИКАТОР ФОРМАТА  %N
    } else if (flags->placeHolder == 'n') {
        int* intPointer = va_arg(*argumentPointer, int*);
        *intPointer = *countOfPrinted;
//СПЕЦЫФИКАТОР ФОРМАТА  %U
    } else if (flags->placeHolder == 'u') {
        int numLength = 0;
        int amountOfSpaces = 0;
        int amountOfZeroes = 0;
        int pointJump = 0;
        unsigned int unsArgNum = 0;
        unsigned short unsArgNumS = 0;
        unsigned long unsArgNumL = 0;
        if (flags->accuracyPoint)
            flags->zero = 0;
        if (flags->minus)
            flags->zero = 0;
        if (flags->len == 'h') {
            unsArgNumS = va_arg(*argumentPointer, unsigned int);
            numLength = s21_intNumLen(unsArgNumS, 10); ///////////////// ЗАЧЕМ НУЖНО УТОЧНЕНИЕ ДЛИННЫ ТИПА
        } else if (flags->len == 'l') {
            unsArgNumL = va_arg(*argumentPointer, unsigned long);
            numLength = s21_intNumLen(unsArgNumS, 10); ///////////////// ЗАЧЕМ НУЖНО УТОЧНЕНИЕ ДЛИННЫ ТИПА
        } else {
            unsArgNum = va_arg(*argumentPointer, unsigned int);
            numLength = s21_intNumLen(unsArgNum, 10); ///////////////// ЗАЧЕМ НУЖНО УТОЧНЕНИЕ ДЛИННЫ ТИПА
        }
        if (flags->accuracy > numLength) {
            amountOfZeroes = flags->accuracy - numLength;
            if (flags->width > flags->accuracy)
                amountOfSpaces = flags->width - flags->accuracy;        
        } else
            if (flags->width > numLength)
                amountOfSpaces = flags->width - numLength;
        if (flags->minus) {
            for (int i = 0; i < amountOfZeroes; i++) {
                **str = '0';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
            if (flags->len == 'h') {
                pointJump = s21_numToStr(unsArgNumS, *str, 10, 0, countOfPrinted, 0); /////////////////
            } else if (flags->len == 'l') {
                pointJump = s21_numToStr(unsArgNumL, *str, 10, 0, countOfPrinted, 0); /////////////////
            } else {
                pointJump = s21_numToStr(unsArgNum, *str, 10, 0, countOfPrinted, 0); /////////////////
            }
            *str = *str + pointJump;
            for (int i = 0; i < amountOfSpaces; i++) {
                **str = ' ';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
        } else {
            for (int i = 0; i < amountOfSpaces; i++) {
                **str = (flags->zero) ? '0' : ' ';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
            for (int i = 0; i < amountOfZeroes; i++) {
                **str = '0';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
            if (flags->len == 'h') {
                pointJump = s21_numToStr(unsArgNumS, *str, 10, 0, countOfPrinted, 0); /////////////////
            } else if (flags->len == 'l') {
                pointJump = s21_numToStr(unsArgNumL, *str, 10, 0, countOfPrinted, 0); /////////////////
            } else {
                pointJump = s21_numToStr(unsArgNum, *str, 10, 0, countOfPrinted, 0); /////////////////
            }
            *str = *str + pointJump;
        }
//СПЕЦЫФИКАТОР ФОРМАТА  %oxX
    } else if (flags->placeHolder == 'o' || flags->placeHolder == 'x' || flags->placeHolder == 'X') {
        int numSys = 0;
        if (flags->placeHolder == 'o')
            numSys = 8;
        if (flags->placeHolder == 'x' || flags->placeHolder == 'X')
            numSys = 16;
        int numLength = 0;
        int amountOfSpaces = 0;
        int amountOfZeroes = 0;
        int pointJump = 0;
        unsigned int ArgNum = 0;
        unsigned short ArgNumS = 0;
        unsigned long ArgNumL = 0;
        if (flags->accuracyPoint)
            flags->zero = 0;
        if (flags->minus)
            flags->zero = 0;
        if (flags->len == 'h') {
            ArgNumS = va_arg(*argumentPointer, unsigned int);
            numLength = s21_intNumLen(ArgNumS, numSys); ///////////////// ЗАЧЕМ НУЖНО УТОЧНЕНИЕ ДЛИННЫ ТИПА
        } else if (flags->len == 'l') {
            ArgNumL = va_arg(*argumentPointer, unsigned long);
            numLength = s21_intNumLen(ArgNumS, numSys); ///////////////// ЗАЧЕМ НУЖНО УТОЧНЕНИЕ ДЛИННЫ ТИПА
        } else {
            ArgNum = va_arg(*argumentPointer, unsigned int);
            numLength = s21_intNumLen(ArgNum, numSys); ///////////////// ЗАЧЕМ НУЖНО УТОЧНЕНИЕ ДЛИННЫ ТИПА
        }
        int additionalnNumLen = 0;
        if (flags->lattice)
            additionalnNumLen = (numSys == 8) ? 1 : 2;


////////
        if(flags->accuracyPoint) {
            if (flags->accuracy > numLength) {
                amountOfZeroes = flags->accuracy - numLength;
                if (flags->width > flags->accuracy)
                    amountOfSpaces = flags->width - flags->accuracy;        
            } else
                if (flags->width > numLength)
                    amountOfSpaces = flags->width - numLength;
        } else if (flags->zero)
            amountOfZeroes = flags->width - numLength;
        else
            amountOfSpaces = flags->width - numLength;
////////


        if (flags->minus) {

            if (numSys == 16 && flags->lattice)
                amountOfSpaces -= 2;
            if (flags->lattice) {
                if (numSys == 8) {
                    **str = '0';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                } else {
                    **str = '0';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = (flags->placeHolder == 'x') ? 'x' : 'X';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                }
            }            
            for (int i = 0; i < amountOfZeroes; i++) {
                **str = '0';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }            
            if (flags->len == 'h') {
                pointJump = s21_numToStr(ArgNumS, *str, numSys, 0, countOfPrinted, (flags->placeHolder == 'X') ? 1 : 0); /////////////////
            } else if (flags->len == 'l') {
                pointJump = s21_numToStr(ArgNumL, *str, numSys, 0, countOfPrinted, (flags->placeHolder == 'X') ? 1 : 0); /////////////////
            } else {
                pointJump = s21_numToStr(ArgNum, *str, numSys, 0, countOfPrinted, (flags->placeHolder == 'X') ? 1 : 0); /////////////////
            }
            *str = *str + pointJump;
            for (int i = 0; i < amountOfSpaces; i++) {
                **str = ' ';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }

        } else {

            if (numSys == 16 && flags->lattice) {
                amountOfSpaces -= 2;
                if (flags->zero) 
                    amountOfZeroes -= 2;
            }
            if (numSys == 8 && flags->lattice)
                if (flags->accuracy <= numLength)
                    amountOfSpaces--;    
            for (int i = 0; i < amountOfSpaces; i++) {
                **str = ' ';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
            if (flags->lattice) {
                if (numSys == 8) {
                    if (flags->accuracy <= numLength && !flags->zero) {
                        **str = '0';
                        *countOfPrinted = *countOfPrinted + 1;
                        *str = *str + 1;
                        **str = '\0';
                    }
                } else {
                    **str = '0';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = (flags->placeHolder == 'x') ? 'x' : 'X';
                    *countOfPrinted = *countOfPrinted + 1;
                    *str = *str + 1;
                    **str = '\0';
                }
            }
            for (int i = 0; i < amountOfZeroes; i++) {
                **str = '0';
                *countOfPrinted = *countOfPrinted + 1;
                *str = *str + 1;
                **str = '\0';
            }
            if (flags->len == 'h') {
                pointJump = s21_numToStr(ArgNumS, *str, numSys, 0, countOfPrinted, (flags->placeHolder == 'X') ? 1 : 0); /////////////////
            } else if (flags->len == 'l') {
                pointJump = s21_numToStr(ArgNumL, *str, numSys, 0, countOfPrinted, (flags->placeHolder == 'X') ? 1 : 0); /////////////////
            } else {
                pointJump = s21_numToStr(ArgNum, *str, numSys, 0, countOfPrinted, (flags->placeHolder == 'X') ? 1 : 0); /////////////////
            }
            *str = *str + pointJump;
        }



    } else if (flags->placeHolder == 'd' || flags->placeHolder == 'i') {
    
    }    
}
