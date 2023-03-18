#include <stdio.h>
#include <stdlib.h>

int main()
{
    //rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX).

    for(int i=0; i<5;i++)
    {
        printf("%d\n",rand());
    }
    return 0;
}


