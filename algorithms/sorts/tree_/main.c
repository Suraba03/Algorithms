#include <stdio.h>
#include "sort.h"
#include "tree.h"

int main(void)
{
    int arr[12] = {2, 245, -24, 245, 2, 5, 8, -26, 460, 24, 2460, -24624};
    tree_sort(arr);
    printf("\n");
    return 0;
}