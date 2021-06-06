#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int *m)
{
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            if (m[j] > m[j + 1]) {
                swap(&m[j], &m[j + 1]);
            }
        }
    }
}