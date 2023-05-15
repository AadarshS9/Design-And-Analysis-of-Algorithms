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

void nexta(int arr[],int temp, int size)
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

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*tail=NULL,*temp=NULL,*temp2=NULL,*pos=NULL;

void insert(int num)
{
    if(head==NULL)
{
	head=(struct node*)malloc(sizeof(struct node));
	head->data=num;
	head->next=NULL;
	tail=head;
}
else
{
	tail->next=(struct node*)malloc(sizeof(struct node));
	tail=tail->next;
	tail->data=num;
	tail->next=NULL;
}
}

void delete(int num)
{
    struct node *temp=head;

if(head==NULL)
{
	printf("Nothing to delete");
}

int count=0;pos=head;
while(pos!=NULL)
{
	pos=pos->next;
	count++;
}

if(num>count-1)
{
	printf("Out of range\n");
}

else if(num==0)
{
	head=head->next;
	temp->next=NULL;
	free(temp);
}

else if(num==count-1)
{
	for(int i=0;i<num-1;i++)
	{
		temp=temp->next;
	}
	tail=temp;
	temp=tail->next;
	tail->next=NULL;
	free(temp);
}

else
{
	for(int i=0;i<num-1;i++)
	{
		temp=temp->next;
	}
	struct node *del=temp->next;
	temp->next=temp->next->next;
	del->next=NULL;
	free(del);
	}
}

void next(int pos)
{
	int max=__INT_MAX__;
    temp2=head;
    for(int i=0;i<pos;i++)
	{
		temp2=temp2->next;
	}
  // printf("%d",temp2->data);
    temp=head;
	while(temp!=NULL)
	{
		if((temp->data)>temp2->data && (temp->data)<max)
		{
			max=temp->data;
		}
		temp=temp->next;
	}

	if(max==__INT_MAX__)
    {
        printf("Error! No larger element exists.\n");
    }
    else
        printf("The next largest element is: %d\n",max);
}

void display()
{
    pos=head;

	if(pos==NULL)
	{
		printf("Nothing to print");
	}
	else
	{
		while(pos!=NULL)
		{
			printf("%d\t",pos->data);
			pos=pos->next;
		}
	}
	printf("\n");
}

void main()
{
    int size,i,j,pos;
    printf("\nKindly enter size of elements: ");
    scanf("%d",&size);
  	int arr[size];
   
	printf("\nArray elements: \n");  
    srand(time(0));
    for(i=0;i<size;i++)
    {
        arr[i]=rand()%100;
        printf("%d\t",arr[i]);
        insert(arr[i]);
    }
    printf("\nLinked list elements: \n");
    display();
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
        printf("ARRAY OPERATION\n");
        start_t = clock();
		printf("Starting Array Deletion timer, start_t = %ld\n", start_t);
        removearr(arr,pos,size);
        end_t = clock();
    	printf("Ending Array Deletion timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Array Deletion time taken by CPU: %f\n", total_t);
        printf("\n");
        for(i=0;i<size-1;i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");
        start_t = clock();
		printf("\nStarting Array Next_Larger timer, start_t = %ld\n", start_t);
   	 	//printf("\n");
        nexta(arr,temp,size);
        //printf("\n");
        end_t = clock();
    	printf("Ending Array Next_Larger timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Array Next_Larger time taken by CPU: %f\n", total_t);

    	printf("\nLINKED LIST OPERATION\n");
		printf("\nStarting Linked List Next_Larger timer, start_t = %ld\n", start_t);
		//printf("\n");
        next(pos);
     	//printf("\n");
        end_t = clock();
    	printf("Ending Linked List Next_Larger timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Linked List Next_Larger time taken by CPU: %f\n", total_t);
		start_t = clock();
		printf("\nStarting Linked List Deletion timer, start_t = %ld\n", start_t);
		delete(pos);
        end_t = clock();
    	printf("Ending Linked List Deletion timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Linked List Deletion time taken by CPU: %f\n", total_t);
        printf("\n");
        display();     
    } 
}
