// WAP to find out the maximum and the second maximum number from an array of integers

#include <stdio.h>


int main()
{
	int i,j,temp;
	int array[5] = {3,2,4,1,5};

	for(i=0; i < 5; i++)
	{
		for(j= i+1; j < 5; j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	for(i=0;i<5;i++)
		printf("%d\t",array[i]);
	printf("\n");

	printf("Maximum Value:%d\n",array[4]);
	printf("Second maximum:%d\n",array[3]);

return 0;
}
