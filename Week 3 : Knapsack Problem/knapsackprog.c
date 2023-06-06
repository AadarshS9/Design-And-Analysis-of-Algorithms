#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,temp,maxw;
	printf("Kindly enter number of elements: ");
	scanf("%d",&n);
	printf("\n");
	
	float pw[n],sol[n],p[n],w[n],eid[n];
	for(int i=0;i<n;i++)
	{
		eid[i]=i+1;
		printf("Kindly enter profit of element %d: ",i+1);
		scanf("%f",&p[i]);
		printf("Kindly enter weight of element %d: ",i+1);
		scanf("%f",&w[i]);
	}
	
	printf("\n");
	printf("Kindly enter maximum weight: ");
	scanf("%d",&maxw);
	printf("\n");
	
	printf(" OBJECT\t ");
	for(int i=0;i<n;i++)
	{
		printf(" %d\t\t",i+1);
	}
	
	printf("\n PROFIT\t ");
	for(int i=0;i<n;i++)
	{
		printf(" %f\t",p[i]);
	}

	printf("\n WEIGHT\t ");
	for(int i=0;i<n;i++)
	{
		printf(" %f\t",w[i]);
	}	
	
		
	for(int i=0;i<n;i++)
	{
		sol[i]=0.0; //initialise solution tuple
	}
	printf("\n");
	printf(" RATIO\t ");
	for(int i=0;i<n;i++)
	{
		pw[i]=p[i]/w[i];
		printf(" %f\t",pw[i]); // calculate profit/weight ratio
	}

	for(int x=0;x<n-1;x++) //sort weight
	{       
		for(int y=0;y<n-x-1;y++)
		{          
		    if(pw[y] < pw[y + 1])
		    {               
		        temp = pw[y];
		        pw[y] = pw[y + 1];
		        pw[y + 1] = temp;
		        
		        temp = p[y];
		        p[y] = p[y + 1];
		        p[y + 1] = temp;
		        
		        temp = w[y];
		        w[y] = w[y + 1];
		        w[y + 1] = temp;
		        
		        temp = eid[y];
		        eid[y] = eid[y + 1];
		        eid[y + 1] = temp;
		     
		    }
		}
	}
	
	int u,i;
	float tp;
	u=maxw;
	for(i=0;i<n;i++)
	{
		if(w[i]>u)
			break;
		
		else
		{
			sol[i]=1.0;
			tp=tp+p[i];
			u=u-w[i];
		}
	}
	
	if(i<=n)
		sol[i]=u/w[i];
	
	tp=tp+(sol[i]*p[i]);
	
	for(int x=0;x<n-1;x++) //sort solution tuple
	{       
		for(int y=0;y<n-x-1;y++)
		{          
		    if(eid[y] > eid[y + 1])
		    {               
		        temp = eid[y];
		        eid[y] = eid[y + 1];
		        eid[y + 1] = temp;
		        
		        temp = pw[y];
		        pw[y] = pw[y + 1];
		        pw[y + 1] = temp;
		        
		        temp = p[y];
		        p[y] = p[y + 1];
		        p[y + 1] = temp;
		        
		        temp = w[y];
		        w[y] = w[y + 1];
		        w[y + 1] = temp;
		        
		        temp = sol[y];
		        sol[y] = sol[y + 1];
		        sol[y + 1] = temp;
		     
		    }
		}
	}
	
	printf("\n");
	printf(" ANSWER\t ");
	for(int i=0;i<n;i++)
	{
		printf(" %f\t",sol[i]); // calculate profit/weight ratio
	}
	printf("\n");	
	printf("\nTotal Profit is %f",tp);
	printf("\n");
}
		

