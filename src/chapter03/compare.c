//
// Created by changwang on 1/9/20.
//
#include "apue.h"
#include <string.h>
#include <ctype.h>

typedef int (fptrOperation)(const char*, const char*);
char* stringToLower(const char*);

void
sort(char* array[], int size, fptrOperation operation)
{
    int swap = 1;
    while (swap) {
        swap = 0;
        for(int i = 0; i < size-1; i++) {
            if(operation(array[i], array[i+1]) > 0) {
                swap = 1;
                char *tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }
}

int
compare(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

int compareIgnoreCase(const char *str1, const char *str2)
{
    char *t1 = stringToLower(str1);
    char *t2 = stringToLower(str2);

    int result = strcmp(t1, t2);
    free(t1);
    free(t2);
    return result;
}

char *stringToLower(const char *str)
{
    char *tmp = (char*)malloc(strlen(str) + 1);
    char *start = tmp;
    while (*str != 0) {
        *tmp++ = (char)tolower(*(str++));
    }
    *tmp = 0;
    return start;
}

void
display(char *names[], int size)
{
    for(int i = 0; i < size; i++) {
        printf("%s   ", names[i]);
    }
    printf("\n");
}

int
main(void)
{
    char *names1[] = {"Alice", "Ted", "Bob", "Carol", "bob", "alice"};
    char *names2[] = {"Alice", "Ted", "Bob", "Carol", "bob", "alice"};
    sort(names1, 6, compare);
    display(names1, 6);
    sort(names2, 6, compareIgnoreCase);
    display(names2, 6);
    return 0;
}



