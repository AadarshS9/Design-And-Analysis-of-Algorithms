#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define INF 999999

int dist[MAX][MAX] = {0};
int n;
int minCost = INF;
int minPath[MAX];
bool visited[MAX];

void takeInput() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
}

void tsp(int city, int count, int path[], int currentCost) {   
    visited[city] = true;  
    path[count] = city; 
    if (count == n - 1 && dist[city][0] != 0) { 
        int totalCost = currentCost + dist[city][0];    
        if (totalCost < minCost) {  
            minCost = totalCost;
            for (int i = 0; i < n; i++) {
                minPath[i] = path[i];   
            }
        }
    } 
    else {
        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (!visited[nextCity] && dist[city][nextCity] != 0) {  
                tsp(nextCity, count + 1, path, currentCost + dist[city][nextCity]); 
            }
        }
    }
    visited[city] = false; 
}

void printSolution() {
    printf("The cost of the most efficient tour = %d\n", minCost);
    printf("Nodes visited in the most efficient tour: ");
    for (int i = 0; i < n; i++) {
        printf("%c", minPath[i]+65);
        if (i != n - 1) {
            printf(" -> ");
        }
    }
    printf(" -> %c\n", minPath[0]+65); 
}

void main() {
    takeInput();
    int path[MAX];
    tsp(0, 0, path, 0);
    printSolution();
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
