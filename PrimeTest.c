#include <stdio.h>
//Generate Prime Numbers
//Prime Number is a number which divides by itself
enum bool
{
   FALSE = 0,
   TRUE = 1
};

typedef enum bool BOOL;
#if 0
BOOL isPrime(long num)
{
   long c = 2;
   //Algorithm to check prime or not
   #if 0
   for( c = 2; c<= num -1; c++ )
   {
      if(num%c == 0)
        return FALSE;
   }
   if(num == c)
      return TRUE;
   #endif
   //Recursive
}
#endif

BOOL isPrime(long num,long i)
{

    if(i==1)
    {
        return TRUE;
    }
    else
    {
       if(num%i==0)
         return FALSE;
       else
         isPrime(num,i-1);
    }
}

int main()
{
   long m,n,i;
   unsigned int no_test_cases;
   BOOL val;

   //Number of Test cases
   //printf("Test case:");
   scanf("%d",&no_test_cases);
   //printf("\n");

   //Give The range
   //1<=m<=n<=1000000000
   //printf("Enter the range\n");
  while(no_test_cases--)
   {
      scanf("%ld %ld",&m,&n);
      if((n-m) <= 100000)
      {
      	for(i=m;i<=n;i++)
   	  	{
      		val = isPrime(i,i/2);
      		if(val == TRUE)
         	printf("%ld\n",i);
   	  	}
   	  }
   	  else
   	  	continue;
   }
   
   
   return 0;
}
