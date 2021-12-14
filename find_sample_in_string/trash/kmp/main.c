#include <stdio.h>
#include <string.h>
#include "kmp.h"

#define SIZE 100

int main(void)
{
    int a[SIZE], *p;
    p = a;

    int j = 0;
    char str[SIZE];
    char sample[SIZE];
    
    printf("строка: ");
    scanf("%s", str);
    printf("ищем строку: ");
    scanf("%s", sample);

    size_t sl = strlen(sample); // длина s
    size_t inl = strlen(str); // длина in
    sample[sl] = '#'; // добавляем в конец sample #
    sl++;
    char *conc_in = strcat(sample, str); // получаем строку вида sample#str
    p = prefix(conc_in, p, strlen(conc_in)); // получаем массив префиксов 

    for (int i = sl; i < sl + inl; i++) { // выводим все индексы начала вхождений
        if (p[i] == sl - 1) { // суть алгоритма: вхождение там, где элемент 
            printf("%d ", i - sl - 1); // массива префиксов равен длине образца
        }
    }

    printf("\n");

    return 0;
}