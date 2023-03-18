#include <stdio.h>
#include <stdlib.h>

int main()
{
    //srand() function sets the starting point for producing a series of pseudo-random integers.
    srand(0);

    for(int i=0; i<5;i++)
    {
        printf("%d\n",rand());
    }

    return 0;
}




