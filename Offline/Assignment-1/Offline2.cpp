#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long long swap1,comp;

void bubble_sort(int a[], int n)
{
    int i,j,temp;
    swap1=0,comp=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap1++;
            }
            comp++;
        }
    }
    printf("\nBubble Sort:\nNo. of swap:%lld \nNo. of comparison:%lld\n",swap1,comp);
}


void insertion_sort(int a[], int n)
{
     int i, key, j;
     swap1=0,comp=0;
     for (i=1; i<n; i++)
     {
        key=a[i];
        j=i-1;
        comp++;
        while(j>=0 && a[j]>key)
        {
            comp++;
            a[j+1]=a[j];
            j=j-1;
            swap1++;
        }
        a[j+1] = key;
    }

    printf("Insertion Sort:\nNo. of swap:%lld \nNo. of comparison:%lld\n",swap1,comp);
}



void selection_sort(int a[], int n)
{
    int i,j,min_index,temp;
    swap1=0,comp=0;
    for(i=0; i<n-1; i++)
    {
        min_index = i;
        for(j=i+1; j<n; j++)
        {
            comp++;
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
            swap1++;
        }
    }
    printf("Selection Sort:\nNo. of swap:%lld \nNo. of comparison:%lld\n",swap1,comp);
}


int main()
{
    int arr[1005];
    int upper,i;
    clock_t start_time, end_time;
    double bubble_time, selection_time, insertion_time;


    printf("Enter the Upper bound: ");
    scanf("%d", &upper);


    srand(time(0));
    for(i=0; i<1000; i++)
    {
        arr[i]=rand()%upper+1;
    }
    start_time = clock();
    bubble_sort(arr,1000);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for bubble sort: %lf\n\n",bubble_time);


    srand(time(0));
    for(i=0; i<1000; i++)
    {
        arr[i]=rand()%upper+1;
    }
    start_time = clock();
    insertion_sort(arr,1000);
    end_time = clock();

    insertion_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for insertion sort: %lf\n\n",insertion_time);


    srand(time(0));
    for(i=0; i<1000; i++)
    {
        arr[i]=rand()%upper+1;
    }
    start_time = clock();
    selection_sort(arr,1000);
    end_time = clock();

    selection_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for selection sort: %lf\n",selection_time);


    return 0;


}




