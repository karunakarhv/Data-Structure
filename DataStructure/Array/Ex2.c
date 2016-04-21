// WAP that accepts a number as input in English language format
// such as One Twenty Three and prints the decimal form of it.

#include <stdio.h>
#include <string.h>

int main()
{
	char array[][10] ={0}; 
        char builtInArray[][10] = {"One","Two","Three","Four","Five",
                                   "Six","Seven","Eight","Nine","Ten",
				  }
	int i;

	printf("Enter the words\n");

        for(i=0;i<3;i++)
	{
		gets(array[i]);
	}
	
	strcmp(array[i],"")
	
	return 0;
}
