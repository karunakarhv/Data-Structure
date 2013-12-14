#include <stdio.h>

void at(int a)
{
   printf("Inside Function A and value is %d",a);
}

void debug(int a, const char *functionName)
{
   printf("A called function name is %s\n",functionName);
}

#define at(a) debug(a,__func__)

void bt()
{
   printf("Inside function b\n");
   at(10);
}

int main()
{
   printf("Inside Main\n");
   bt();

   return 0;
}
