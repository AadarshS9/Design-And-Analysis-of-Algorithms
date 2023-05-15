#include<stdio.h>
#include<stdlib.h>
#include<time.h>

clock_t start_t, end_t;
double total_t;

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

	if (max==__INT_MAX__)
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
		printf("Elements are: ");
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
    printf("\nKindly enter size of linked list: ");
    scanf("%d",&size);
   
    	
    srand(time(0));
    for(i=0;i<size;i++)
    {
        insert(rand()%100);
    }
    display();
   
    printf("\nKindly enter position to be deleted: ");
    scanf("%d",&pos);
    if(pos>=size)
    {
            printf("Error! Position is out of range\n");
    }
   
    else
    {
        printf("\nStarting Next_Larger timer, start_t = %ld\n", start_t);
   		 printf("\n");
        next(pos);
         printf("\n");
        end_t = clock();
    	printf("Ending Next_Larger timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Next_Larger time taken by CPU: %f\n", total_t);
		
        start_t = clock();
		printf("\nStarting Deletion timer, start_t = %ld\n", start_t);
        delete(pos);
        end_t = clock();
    	printf("Ending Deletion timer, end_t = %ld\n", end_t);
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("Total Deletion time taken by CPU: %f\n", total_t);
        printf("\n");
        display();
    }

}
