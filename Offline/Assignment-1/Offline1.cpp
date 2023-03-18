#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long long swap1,com;

void bubble_sort(int a[], int n)
{
    int i,j,temp;
    swap1=0,com=0;

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
            com++;
        }
    }
    printf("\nBubble Sort:\nNo. of swap:%lld \nNo. of comparison:%lld\n",swap1,com);
}


void insertion_sort(int a[], int n)
{
     int i,j,key;
     com=0,swap1=0;

     for (i=1; i<=n; i++)
     {
         key=a[i];
         j=i-1;
         com++;
         while(j>=0 && a[j]>key)
         {
            com++;
            a[j+1]=a[j];
            j=j-1;
            swap1++;
         }
         a[j+1] = key;

     }
     printf("Insertion Sort:\nNo. of swap:%lld \nNo. of comparison:%lld\n",swap1,com);
}


void selection_sort(int a[], int n)
{
    int i,j,min_index,temp;
    swap1=0,com=0;
    for(i=0; i<n-1; i++)
    {
        min_index = i;
        for(j=i+1; j<n; j++)
        {
            com++;
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
    printf("Selection Sort:\nNo. of swap:%lld \nNo. of comparison:%lld\n",swap1,com);
}



int main()
{
    int arr[500000];
    int len, i;
    clock_t start_time, end_time;
    double bubble_time;
    double selection_time;
    double insertion_time;
    printf("Enter array length: ");
    scanf("%d", &len);

    srand(time(0));
    for(i=0; i<len; i++){
        arr[i]=rand()%100+1;
    }

    start_time = clock();
    bubble_sort(arr,len);
    end_time = clock();

    bubble_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time for bubble sort: %lf\n\n",bubble_time);


    srand(time(0));
    for(i=0; i<len; i++){
        arr[i]=rand()%100+1;
    }
    start_time = clock();
    insertion_sort(arr,len);
    end_time = clock();

    insertion_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for insertion sort: %lf\n\n",insertion_time);


    srand(time(0));
    for(i=0; i<len; i++){
        arr[i]=rand()%100+1;
    }
    start_time = clock();
    selection_sort(arr,len);
    end_time = clock();

    selection_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time for selection sort: %lf\n\n",selection_time);

    return 0;


}



