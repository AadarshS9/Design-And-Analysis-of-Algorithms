// Program - Quick Sort
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int array[10000];
void quicksort (int [], int, int);
int  partition(int[], int, int);
void swap(int*, int*);
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    
	int i,key,ch;
	long size,limit;
	printf("Enter number of Elements: ");
	scanf("%ld",&size);
	int array[size];
	printf("Enter upper limit in terms of place Values: ");
	scanf("%lgnuplod",&limit);
	
	int num=size;
	int j,x,y,temp;
	srand( (unsigned) time(NULL) * getpid());
	gettimeofday(&t0, NULL);
	if(array != NULL)
	{
		for(j = 0; j < num; j++)
		{
			array[j] = rand()%limit;
		}
	}
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\n");
	printf("List of Numbers\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\n",array[j]);
	}				
	printf("Random Generation code executed in %f milliseconds.\n", elapsed);
    printf("\n");
    
    gettimeofday(&t0, NULL);
    quicksort(array,0,size-1);
    gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
    printf("Quick Sorted List of Numbers\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\n",array[j]);
	}
   printf("Quick Sort Code executed in %f milliseconds.\n", elapsed);
}

void quicksort(int arr[], int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quicksort(arr, start, pIndex-1);
        quicksort(arr, pIndex+1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pIndex = start;
    int pivot = arr[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
*y = t;
}
