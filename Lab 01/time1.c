#include <stdio.h>
#include <time.h>

int main()
{
    int i,j;
    clock_t start_time, end_time;
    double time_passed;

    start_time = clock();
    for(i=0;i<10000;i++)

    end_time = clock();
    time_passed = (double)(end_time-start_time)/CLOCKS_PER_SEC;

    printf("Time: %lf seconds\n", time_passed);

    return 0;
}
