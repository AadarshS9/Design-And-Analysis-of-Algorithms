#include <stdio.h>
#define MAX_CITY 10
#define INF 999

int ary[MAX_CITY][MAX_CITY], completed[MAX_CITY], n, minCost = INF;
int minPath[MAX_CITY];

void takeInput()
{
    int i, j;

    printf("Enter the number of Cities: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Matrix\n");

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
		completed[i] = 0;
	}
}

void printCostMatrix()
{
	int i, j;
	printf("\n\nThe Cost Matrix:\n");
	printf("\t");
	for (i = 0; i < n; i++)
		printf("%c\t", 'A' + i);
	printf("\n");
	for (i = 0; i < n; i++) 
	{
		printf("%c\t", 'A' + i);
		for (j = 0; j < n; j++)
			printf("%d\t", ary[i][j]);
        printf("\n");
	}
}

void mincost(int city, int count, int path[], int currentCost) 
{
	int i, ncity;
	completed[city] = 1;
 	path[count] = city;

	if (count == n - 1 && ary[city][path[0]] != 0) 
	{
        	if (currentCost + ary[city][path[0]] < minCost)
        	{
			minCost = currentCost + ary[city][path[0]];
            	for (i = 0; i < n; i++)
                	minPath[i] = path[i];
        	}
    	}
	else{
		for (ncity = 0; ncity < n; ncity++) 
		{
			if (!completed[ncity] && ary[city][ncity] != 0) 
			{
				mincost(ncity, count + 1, path, currentCost + ary[city][ncity]);
			}
        	}
	}
	completed[city] = 0;
}

int main() 
{
	takeInput();
	printCostMatrix();
	int path[MAX_CITY];
	mincost(0, 0, path, 0); // Start from city 0
	printf("\nMinimum cost is %d\n", minCost);
	printf("Minimum Cost Path: ");
	for (int i = 0; i < n; i++)
	printf("%c ", 'A' + minPath[i]);
	printf("A\n");
	return 0;
}

// TEST CASES:
// int dist[MAX][MAX] = {  { 0, 2, 0, 12,  5},
//                         { 2, 0, 4,  8,  0},
//                         { 0, 4, 0,  3,  3},
//                         {12, 8, 3,  0, 10},
//                         { 5, 0, 3, 10,  0}};
// int n=5; 
//    A->B->D->C->E->A mincost: 21

// int dist[MAX][MAX] = {  {0, 10, 15, 20},
//                         {5, 0, 9, 10},
//                         {6, 13, 0, 12},
//                         {8, 8, 9 , 0}};
// int n=4;  
//  A->B->D->C->A  mincost: 35
