#include <stdio.h>
int main(){
    int i,n,arr[100];

    printf ("Enter size of the array : ");
    scanf ("%d",&n);
    printf ("\nEnter array elements :");
    for(i=0;i<n;i++)
        scanf ("%d",&arr[i]);
    int k,flag=0;
    printf ("\nEnter a value to search : ");
        scanf("%d",&k);
    for(i=0; i<n; i++){
        if(arr[i]==k){
            flag=1;
            break;
        }
    }
    if (flag==1)
        printf("\nSearched value found at position %d\n",i+1);
    else
        printf("\nSearched value not found\n");
}
