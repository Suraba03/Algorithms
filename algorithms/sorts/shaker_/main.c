#include <stdio.h>
#include "sort.h"

int main(void)
{
    int arr[12] = {2, 245, -24, 245, 2, 5, 8, -26, 460, 24, 2460, -24624};
    shaker(arr);
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}