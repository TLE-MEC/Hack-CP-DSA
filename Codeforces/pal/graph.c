//Adjency matrix
// Question 1
#include<stdio.h>
#define V 10
#define MAX 100
void init(int arr[][V])
{
    int i,j;
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            arr[i][j] = 0;
}
void addEdgeDirected(int arr[][V],int src, int dest)
{
     arr[src][dest] = 1;
}
void addEdgeUnDirected(int arr[][V],int src, int dest)
{
     arr[src][dest] = 1;
     arr[dest][src] = 1;
}
 void chkAdj(int arr[][V],int src, int dest){
    // theta(1) time complexity\
    // works for both
    if(arr[src][dest] == 1){
        printf("Yes\n");
    }else{
        printf("Yes\n");
    }
}
void FindAllAdj(int arr[][V],int src){
    // Works for all
    for(int i = 0; i < V; i++){
        if(arr[src][i]==1){
            printf("%d---%d\n",src,i);
        }
    }
}
void Degree(int arr[][V],int src){
    // Works for all
    int deg=0;
    for(int i = 0; i < V; i++){
        if(arr[src][i]==1){
           deg++;
        }
    }
     printf(" Degree: %d\n",deg);
}
void RemoveEdgeDirected(int arr[][V],int src, int dest){
 arr[src][dest] = 0;
}
void RemoveEdgeUnDirected(int arr[][V],int src, int dest){
     arr[src][dest] = 0;
     arr[dest][src] = 0;
}
void printAdjMatrix(int arr[][V])
{
     int i, j;

     for(i = 1; i <=V; i++)
     {
         for(j = 1; j <= V; j++)
         {
             printf("%d ", arr[i][j]);
         }
         printf("\n");
     }
}

int main()
{
    int adjMatrix[V][V];
    int adjMatrix1[V][V];

    init(adjMatrix);
    init(adjMatrix1);
   
    addEdgeUnDirected(adjMatrix1,1,2);
    addEdgeUnDirected(adjMatrix1,1,3);
    addEdgeUnDirected(adjMatrix1,2,3);
    addEdgeUnDirected(adjMatrix1,2,4);
    addEdgeUnDirected(adjMatrix1,2,5);
    addEdgeUnDirected(adjMatrix1,4,5);
    addEdgeUnDirected(adjMatrix1,3,6);
    addEdgeUnDirected(adjMatrix1,3,7);
    addEdgeUnDirected(adjMatrix1,6,7);
    addEdgeUnDirected(adjMatrix1,4,8);
    addEdgeUnDirected(adjMatrix1,8,9);
    addEdgeUnDirected(adjMatrix1,9,10);
    
    printAdjMatrix(adjMatrix1);
    printf("\n");

    return 0;
}