#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int *m)
{
    for (int i = 0; i < 12; i++) {
        int key = m[i];
        int j = i - 1;
        while (key < m[j] && j >= 0) {
            m[j + 1] = m[j];
            j--;
        }
        m[j + 1] = key;
    }
}