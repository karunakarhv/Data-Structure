#include <stdio.h>

int main()
{
   int arr[1000];
   int i = 0i,len=0;

   printf("Input:\n");
   while(1)
   {
      scanf("%d",&arr[i]);
      if(arr[i] == 42) 
      {break;}
      else if(arr[i] > 100) 
      {continue;}
      else
      {
         i++;
      }
   }
   printf("Output:\n");
   for(len = 0;len< i ;len++ )
      printf("%d\n",arr[len]);

   return 0;
}
