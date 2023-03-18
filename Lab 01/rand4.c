#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    for(int i=0; i<5; i++)
    {
        srand(time(0));

        for(int j=0; j<5;j++)
        {
            printf(" %d ",rand());
        }
        printf("\n");
    }

    return 0;
}








