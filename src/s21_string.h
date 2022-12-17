#include <stdio.h>
#include <string.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long

s21_size_t s21_strlen(const char* str); 
s21_size_t s21_strcspn(const char* str1, const char* str2);
s21_size_t s21_strspn(const char* str1, const char* str2);
// void* s21_memcpy(void* dest, const void* src, s21_size_t n);
// void* s21_memmove(void* dest, const void* src, s21_size_t n);
// void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strcpy(char* dest, const char* src);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
// void* s21_memchr(const void* str, int c, s21_size_t n);
char* s21_strrchr(const char* str, int c);
char* s21_strchr(const char* str, int c);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strstr(const char* haystack, const char* needle);
// int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
int s21_strcmp(const char* str1, const char* str2);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strtok(char* str, const char* delim);
// char* s21_strerror(int errnum);
char* s21_strcat(char* dest, const char* src);
char* s21_strncat(char* dest, const char* src, s21_size_t n);

// int s21_sscanf(const char* str, const char* format, ...);
// int s21_sprintf(char* str, const char* format, ...);

