#include "dutility.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ndigit(int val)
{
    if (val == 0)
        return 1;
    
    int digit_count = 0;

    while (val) {
        ++digit_count;
        val /= 10;
    }

    return digit_count;
}

int isprime(int val)
{
    if (val == 0 || val == 1)
        return 0;
    
    if (val % 2 == 0)
        return val == 2;
    if (val % 3 == 0)
        return val == 3;
    if (val % 5 == 0)
        return val == 5;
    
    for (int k = 7; k * k <= val; k += 2)
        if (val % k == 0)
            return 0;
    
    return 1;
}

/*void sleep(int millisecond)
{
    Sleep(millisecond);
}
*/

void putline(void)
{
    printf("\n\n-------------------------------------------------------------------------------\n");
}

void clear_input_buffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ; //null statement
}

void randomize(void)
{
    srand((unsigned)time(0));
}

void print_array(const int* p, int size)
{
    printf("\n");
    for (int i = 0; i < size; ++i) {
        if (i && i % 30 == 0)
            printf("\n");
        printf("%3d ", p[i]);
    }
}

void set_random_array(int* p, int size)
{
    for (int i = 0; i < size; ++i)
    {
        p[i] = rand() % 1000;
    }
}
