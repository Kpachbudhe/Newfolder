#include <stdio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int G[MAX][MAX], int n, int startnode);
int main()
{
int G[MAX][MAX], i, j, n, u;
printf("Enter no. of vertices :");
scanf("%d", &n);
printf("\nEnter the adjecency matrix : \n");
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &G[i][j]);
printf("\nEnter the starting node :");
scanf("%d", &u);
dijkstra(G, n, u);
return 0;
}
void dijkstra(int G[MAX][MAX], int n, int startnode)
{
int cost[MAX][MAX], distance[MAX], pred[MAX];
int visited[MAX], count, mindistance, nextnode, i, j;
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
if (G[i][j] == 0)
cost[i][j] = INFINITY;
else
cost[i][j] = G[i][j];
for (i = 0; i < n; i++)
{
distance[i] = cost[startnode][i];
pred[i] = startnode;
visited[i] = 0;
}
distance[startnode] = 0;
visited[startnode] = 1;
count = 1;
while (count < n - 1)
{
mindistance = INFINITY;
for (i = 0; i < n; i++)
if (distance[i] < mindistance && !visited[i])
{
mindistance = distance[i];
nextnode = i;
}
visited[nextnode] = 1;
for (i = 0; i < n; i++)
if (!visited[i])
if (mindistance + cost[nextnode][i] < distance[i])
{
distance[i] = mindistance + cost[nextnode][i];
pred[i] = nextnode;
}
count++;
}
for (i = 0; i < n; i++)
if (i != startnode)
{
printf("\n Distance of Node %d = %d", i, distance[i]);
printf("\nPath = %d", i);
j = i;
do
{
j = pred[j];
printf("<-%d", j);
} while (j != startnode);
}
}



OutputEnter no. of vertices :5
Enter the adjecency matrix :
3
6
7
2
8
9
4
9
4
7
1
2
7
5
4
8
3
9
7
8
3
6
9
1
2
Enter the starting node :3
Distance of Node 0 = 8
Path = 0<-3
Distance of Node 1 = 3
Path = 1<-3
Distance of Node 2 = 9
Path = 2<-3
Distance of Node 4 = 8
Path = 4<-3