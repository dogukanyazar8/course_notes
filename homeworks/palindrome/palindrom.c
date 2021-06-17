#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    printf("Bir yazi girin: ");
    sgets(str);
    printf("[%s]\n", str);

    int len = 0, count = 0;

    for (int i = 0; str[i] != '\0'; ++i) //atsahibigibihasta
        if (isalpha(str[i]))
            ++len;

    for (int i = 0; i < len / 2; ++i)
        if (isalpha(str[i]) && isalpha(str[len - i - 1]))
            if (toupper(str[i]) == toupper(str[len - i - 1]))
                ++count;

    if (count == len / 2)
        printf("Palindrom.\n");
    else
        printf("Palindrom degil.\n");
}