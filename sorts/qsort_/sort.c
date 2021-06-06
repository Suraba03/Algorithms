#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *m, int l, int r) // l, r - индексы первого и последнего элементов массива / подмасссива, соответственно
{
    int pivot = m[r]; // пивот - последний элемент
    int i = l - 1;

    for (int j = l; j <= r; j++) {
        if (m[j] <= pivot) {
            i++;
            if (i != j) swap(&m[i], &m[j]);
        }
    }
    return i;
}

void qsort(int *m, int l, int r)
{
    if (l < r)
    {
        int pivot_index = partition(m, l, r);
        qsort(m, l, pivot_index - 1);
        qsort(m, pivot_index + 1, r);
    }
}