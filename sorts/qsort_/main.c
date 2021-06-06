#include <stdio.h>
#include "sort.h"

int main(void)
{
    int arr[12] = {2, 25, -24, 23, 2, 5, 8, -26, 4, 21, 24, 14};
    qsort(arr, 0, 11);
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}