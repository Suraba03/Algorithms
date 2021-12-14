#ifndef __QSORT__
#define __QSORT__

#include <stdio.h>

int partition(int *m, int l, int r);
void swap(int *a, int *b);
void qsort(int *m, int l, int r);

#endif