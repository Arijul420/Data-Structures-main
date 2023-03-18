#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int i,j,temp;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {6,8,1,3,8};
    bubble_sort(arr,5);
    for(int i=0;i<5;i++)
        printf(" %d ", arr[i]);

}
