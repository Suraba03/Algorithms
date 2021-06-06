#include <stdio.h>
#include <string.h>
#include "find.h"

// поиск подстроки (образца) в строке
int simple(char *sample, char *str)
{
    // i - индексы основной строки
    // j - индексы подстроки
    for (int i = 0; i < strlen(str); i++) {
        int flag = 1;
        for (int j = 0; j < strlen(sample); j++) {
            // стравниваем поэлементно
            if (str[j + i] != sample[j]) {
                flag = 0;
                break;
            }
        }
        // если все символы в проходе совпали 
        // удачное завешение алгоритма
        if (flag == 1) {
            return i;
        }
    }
    // неудачное завешение алгоритма
    return -1;
}