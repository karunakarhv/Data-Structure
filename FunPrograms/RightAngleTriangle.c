#include <stdio.h>

int main()
{
	int depth;
	int inc_val = 1;
	int temp = 1;
	int i =0;
	printf("Enter Depth");
	scanf("%d",&depth);
        temp = depth;
	while(temp > 0)
	{
		for(i = 0; i < temp; i++)
		{		
			printf("%d\t",inc_val);
			inc_val++;
		}
		printf("\n");
		temp--;
	}
}
