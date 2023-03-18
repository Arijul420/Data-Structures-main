#include<bits/stdc++.h>
using namespace std;

struct Info
{
    int n;
    int i;
    int j;
    int k;



};
int main()
{
    int n;
    printf("Enter input n:");
    scanf("%d",&n);
    stack <Info> S;
    S.push({n,1,2,3});


    while(S.empty()==0)
    {
        Info cur=S.top();
        S.pop();
        int n,i,j,k;
        n=cur.n;
        i=cur.i;
        j=cur.j;
        k=cur.k;

        if(n==1)
            printf("move from %d to %d\n",i,k);
        else
        {
            S.push({n-1,j,i,k});
            S.push({1,i,j,k});
            S.push({n-1,i,k,j}); /* packet form {} */
        }
    }

}
