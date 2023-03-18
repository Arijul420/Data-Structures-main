#include <stdio.h>

void photocopyShop(int cus)
{
    if(cus==0)
        return;

    printf("Currently serving: %d\n",cus);
    photocopyShop(cus-1);
    printf("Service finished: %d\n",cus);
}

int main()
{
    photocopyShop(4);
    printf("\n!!The End!!\n");
    return 0;
}


