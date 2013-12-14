/*
 * Dijkstra's Algorithm - Single Source Shortest Path Problem
 *
 * The single source shortest path problem is the one 
 * wherein we compute the shortest distance from a given source
 * vertex Vs to all other vertices in the graph.
 *
 * Algorithm: Dijkstra(n,cost,source,destination,d,p)
 *
 * Purpose: To compute the shortest distance and shortest path from
 * given source to destination
 *
 * Input:   n - Number of vertices in the graph
 *          cost - Cost Adjaceny matrix with values >= 0
 *          souce - source vertex
 *          destination - destination vertex
 *
 * Output:  d - shortest distance from source to all other nodes
 *          p - shortest path from source to destination
 *          s - gives the nodes that are so far visited and the nodes
 *          that are not visited
 *
 */
#include <stdio.h>

void dijkstra(int n , int cost[10][10], int source, int destination, int d[], int p[])
{
   int i,j,u,v,min,s[10];

   for(i=0;i<n;i++)
   {
      d[i] = cost[source][i];
      s[i] = 0;
      p[i] = source;
   }

   s[source] = 1; //Add source to S
   

   for(i=0 ; i < n ; i++)
   {
      //Find u and d[u] such that d[u] is minimum and u in V-S
      min = 9999;
      u = -1;

      for(j = 0; j < n ; j++)
      {
         if(s[j] == 0)
         {
            if(d[j] < min)
            {
               min = d[j];
               u = j;
            }
         }
      }
      
      if(u == -1) return;

      s[u] = 1; //Add u to S

      if(u == destination) return;

      /* Find d[v] and p[v] for every v in V-S */
      for(v = 0; v < n; v++)
      {
         if(s[v] == 0)
         {
            if((d[u] + cost[u][v]) < d[v])
            {
               d[v] = d[u] + cost[u][v];
               p[v] = u;
            }
         }
      }
   
   }//Outer most for loop
}

/*
 * Print the shortest path and shortest distance
 */

void print_path(int source, int destination, int d[], int p[])
{
   int i;

   i = destination;

   while(i != source)
   {
      printf("%d <--",i);
      i = p[i];
   }

   printf("%d = %d\n", i, d[destination]);
}

/*
 * Read Data
 */

void read_data(int n, int a[10][10])
{
   int i,j;

   for(i = 0; i < n; i++)
   {
      for(j = 0; j < n; j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
}

/*
 * Main function of the program
 */

int main()
{
   int cost[10][10], n, d[10], p[10], i, j;

   printf("Enter the number of nodes in the graph\n");
   scanf("%d",&n);

   printf("Enter the cost adjaceny matrix\n");
   read_data(n,cost);

   for(i=0; i < n; i++)
   {
      for(j=0; j < n; j++)
      {
         dijkstra(n,cost,i,j,d,p);

         if(d[j] == 9999)
            printf("%d is not reachable from %d\n",j,i);
         else if(i!=j)
            print_path(i,j,d,p);
      }
   }

   return 0;
}
