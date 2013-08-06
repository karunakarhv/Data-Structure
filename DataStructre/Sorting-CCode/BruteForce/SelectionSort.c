#include <stdio.h>

int main()
{
   int a[5];
   int i,j,min,temp;

   printf("\nInput Array");
   for(i=0;i<5;i++)
      scanf("%d",&a[i]);

   for(i=0;i<=3;i++)
   {
      min = i;
      for(j=i+1;j<=4;j++)
      {
         if(a[j] < a[min])
         {
            min = j;
         }
      }
      if(i != min)
      {
         printf("\na[%d] = %d",i,a[i]);
         temp = a[i];
         a[i] = a[min];
         a[min] = temp;
      }
      printf("\nSorted Ith Value:%d \t Min Value %d",a[i],a[min]);
   }
   
   printf("\nSorted Array\n");
   for(i=0;i<5;i++)
      printf("%d\t",a[i]);

   printf("\n\n");
}
