#include <stdio.h>
#include "search.h"

int BinSearchRec(int *m, int key, int l, int r)
{
    int mid = (l + r) / 2;

    if (l <= r) {
        if (key == m[mid]) {
            return mid;
        } else if (key > m[mid]) {
            return BinSearchRec(m, key, mid + 1, r);
        } else {
            return BinSearchRec(m, key, l, mid - 1);
        }
    }
    return -1;
}