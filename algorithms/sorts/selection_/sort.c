#include <stdio.h>
#include <limits.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selection(int *m)
{
    int l = 0, r = 11;
                    //  0    1    2    3  4  5  6    7    8   9    10    11
    while (l < r) { // {2, 245, -24, 245, 2, 5, 8, -26, 460, 24, 2460, -224};

        int max = INT_MIN, min = INT_MAX;
        int max_i = INT_MIN, min_i = INT_MAX;

        for (int i = l; i <= r; i++) {
            if (m[i] > max) {
                max = m[i];
                max_i = i;
            }
        }
        int temp1 = m[r];
        m[r] = max;
        m[max_i] = temp1;

        r--;

        for (int i = l; i <= r; i++) {
            if (m[i] < min) {
                min = m[i];
                min_i = i;
            }
        }
        int temp2 = m[l];
        m[l] = min;
        m[min_i] = temp2;

        l++;
    }
}