#include<stdio.h>
#include<time.h>
#include<stdlib.h>

clock_t start_t, end_t;
double total_t;

void removearr(int arr[], int num, int size)
{
    for(int i=num;i<size-1;i++)
    {
        arr[i] = arr[i+1];
    }
   
}

void next(int arr[],int temp, int size)
{
int max=__INT_MAX__;
for(int i=0;i<size-1;i++)
{
    if(arr[i]>temp && arr[i]<max)
       max=arr[i];
}
if (max == __INT_MAX__)
{
        printf("Error! No larger element exists.\n");
    }
    else
        printf("The next largest element is: %d\n",max);
}
void main()
{
    int size,i,j,pos;
    printf("\nKindly enter size of array: ");
    scanf("%d",&size);
  	int arr[size];
   
	  	
    srand(time(0));
    for(i=0;i<size;i++)
    {
        arr[i]=rand()%100;
        printf("%d\t",arr[i]);
    }
   	printf("\n");
    printf("\nKindly enter position to be deleted: ");
    scanf("%d",&pos);
    printf("\n");
    int temp=arr[pos];
   
    if (pos<0||pos>=size)
    {
        printf("Error! Position is out of range.\n");
        return;
    }
    else
    {
        start_t = clock();
		printf("Starting Deletion timer, start_t = %ld\n", start_t);
   		   		
        removearr(arr,pos,size);
        
        end_t = clock();
    	printf("Ending Deletion timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Deletion time taken by CPU: %f\n", total_t);
        
        printf("\n");
        for(i=0;i<size-1;i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");
        start_t = clock();
		printf("\nStarting Next_Larger timer, start_t = %ld\n", start_t);
   		printf("\n");
   		        
        next(arr,temp,size);
        
        printf("\n");
        end_t = clock();
    	printf("Ending Next_Larger timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Next_Larger time taken by CPU: %f\n", total_t);
        
    }
    
    
    
}
