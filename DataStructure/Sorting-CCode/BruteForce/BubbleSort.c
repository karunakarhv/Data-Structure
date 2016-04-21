#include <stdio.h>

int main()
{
	int a[5] = {7,8,0,2,-1};
	int i,j,temp;
	
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3-i;j++)
		{
			if(a[j+1]< a[j])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("Sorted Array is:");
	for(i=0;i<=4;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
