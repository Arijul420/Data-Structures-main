#include <stdio.h>

void selection_sort(int a[], int n)
{
    int i,j,min_index,temp;

    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
                min_index = j;
            }
        }
        if(min_index!=i)
        {
            temp = a[min_index];
            a[min_index]=a[i];
            a[i] = temp;
        }
    }
}

int main()
{
    int arr[] = {6,8,1,3,8};
    selection_sort(arr,5);
    for(int i=0;i<5;i++)
        printf(" %d ", arr[i]);

}
