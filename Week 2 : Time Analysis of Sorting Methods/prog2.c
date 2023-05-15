// Program - Quick Sort and Bubble Sort
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int array[10000];
void quicksort (int [], int, int);
int  partition(int[], int, int);
void swap(int*, int*);

clock_t start_t, end_t;
double total_t;
double btime,qtime;

int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsedq,elapsedb;
    
    FILE *f;
    f=fopen("sort.dat","a+");
    
	int i,key,ch;
	long size,limit;
	printf("Enter number of Elements: ");
	scanf("%ld",&size);
	int arrayq[size];
	int arrayb[size];
	printf("Enter upper limit in terms of place Values: ");
	scanf("%ld",&limit);
	
	int num=size;
	int j,x,y,temp;
	if(array != NULL)
	{
		for(j = 0; j < num; j++)
		{
			arrayq[j] = rand()%limit;
			arrayb[j]=arrayq[j];
		}
	}
	printf("\n");
	printf("List of Numbers\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\t",arrayq[j]);
	}				
    printf("\n");
    
    start_t = clock();
    quicksort(arrayq,0,size-1);
   	end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    qtime=total_t;
    printf("\nQuick Sorted List of Numbers\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\t",arrayq[j]);
	}
   printf("\nQuick Sort Code executed in %f milliseconds.\n", qtime);
   
   printf("\n");
    start_t = clock();
    for(x = 0; x < num - 1; x++)
	{       
		for(y = 0; y < num - x - 1; y++)
		{          
		    if(arrayb[y] > arrayb[y + 1])
		    {               
		        temp = arrayb[y];
		        arrayb[y] = arrayb[y + 1];
		        arrayb[y + 1] = temp;
		    }
		}
	}
    end_t = clock();
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   btime=total_t;
    printf("Bubble Sorted List of Numbers:\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\t",arrayb[j]);
	}
   printf("\nBubble Sort Code executed in %f milliseconds.\n", btime);
   fprintf(f,"%ld\t%f\t%f\n",size,btime,qtime);
   fclose(f);
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
