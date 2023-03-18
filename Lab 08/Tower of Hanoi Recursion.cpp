#include<bits/stdc++.h>
using namespace std;

void TOH(int n,char src,char aux,char des)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,src,des);
        return;
    }


    TOH(n-1,src,des,aux);
    printf("Move disk %d from %c to %c\n",n,src,des);

    TOH(n-1,aux,src,des);
}
int main(void)
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    TOH( n,'A','B','C');

}
