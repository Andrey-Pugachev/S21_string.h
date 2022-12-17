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

// char* s21_strtok(char* str, const char* delim) {

// }