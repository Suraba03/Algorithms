#include <stdio.h>
#include <string.h>
#include "kmp.h"

// заполнение массива максимальных префикс=суффикс строк
// S(k) - строка, которая явялется префиксом и суффиксом максимальной длины для позиции k
int *prefix(char *s, int *p, int n) // s - исходная строка, p - массив префиксов  
{
    p[0] = 0;
 
    for (int i = 1; i < n; i++) { // 
        int k = p[i - 1]; // 
        while ((k > 0) && (s[i] != s[k])) {
            k = p[k - 1]; // 
        }
        if (s[i] == s[k]) k++; // 
        p[i] = k; // 
    }
    return p;
}