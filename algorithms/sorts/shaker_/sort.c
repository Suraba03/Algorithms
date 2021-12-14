#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shaker(int *m)
{
    int b = 1;
    int l = 0, r = 11;
    while ((l < r) && b) {
        b = 0;
        for (int i = l; i < r; i++) {
            if (m[i] > m[i + 1]) {
                swap(&m[i], &m[i + 1]);
                b = 1;
            }
        }
        r--;
        for (int j = r; j > l; j--) {
            if (m[j] < m[j - 1]) {
                swap(&m[j], &m[j - 1]);
                b = 1;
            }
        }
        l++;
    }
}