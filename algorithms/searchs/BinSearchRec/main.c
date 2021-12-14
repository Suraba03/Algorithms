#include <stdio.h>
#include "sort.h"
#include "search.h"

int main(void)
{
    int arr[12] = {2, 245, -24, 245, 2, 5, 8, -26, 460, 24, 2460, -24624};
    
    qsort(arr, 0, 11);
    
    printf("+------------------+\n");
    printf("| элемент | индекс |\n");

    for (int i = 0; i < 12; i++) {
        printf("+------------------+\n");
        printf("| %7d | %6d |\n", arr[i], BinSearchRec(arr, arr[i], 0, 11));
    }
    printf("+------------------+\n");
    
    return 0;
}