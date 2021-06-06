#include <stdio.h>
#include <string.h>
#include "find.h"

#define STR_SIZE 100

int main(void)
{
    char str[STR_SIZE];
    char sample[STR_SIZE];
    
    printf("строка: ");
    gets(str);
    printf("образец: ");
    gets(sample);

    int i = simple(sample, str);

    if (i != -1) {
        printf("индекс начала образца = %d\nиндекс конца образца = %d\n", i, i + (strlen(sample) - 1));
    } else {
        printf("совпадений не найдено\n");
    }

    return 0;
}