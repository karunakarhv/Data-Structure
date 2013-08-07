#include <stdio.h>

#define MAX 3

void create(int [3][3]);
void display(int [3][3]);
void matadd(int [3][3], int [3][3], int [3][3]);
void matmul(int [3][3], int [3][3], int [3][3]);
void transpose(int [3][3], int [3][3]);

int main()
{
	int a[3][3], b[3][3], c[3][3];
	printf("1st matrix:\n");
	create(a);

	printf("2nd matrix:\n");
	create(b);

	printf("Display the matrix 1:\n");
	display(a);
	
	printf("Display the matrix 2:\n");
	display(b);
	
	printf("Add the two matrix\n");
	matadd(a,b,c);

	printf("Resultant of Adding two matrix\n");
	display(c);

	printf("Multiplication of two matrices\n");
	matmul(a,b,c);
	
	printf("Resultant of Multiplication of two matrix\n");
	display(c);

	printf("Transpose of matrix\n");
	transpose(a,c);

	printf("Resultant of Transpose of matrix\n");
	display(c);

	return 0;
}

void create(int array[3][3])
{
	int i,j;
	printf("Enter the elements of the matrix\n");
	for(i=0;i<MAX;i++)
	{
		for(j=0; j < MAX; j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
}

void display(int array[3][3])
{
	int i,j;
	for(i=0; i<MAX; i++)
	{
		for(j=0; j < MAX; j++)
		{
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
}

void matadd(int a[3][3], int b[3][3], int c[3][3])
{
	int i,j;
	for(i=0; i < MAX; i++)
	{
		for(j=0; j < MAX; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void matmul(int a[3][3], int b[3][3], int c[3][3])
{
	int i,j,k,sum=0;

        for(k=0; k < MAX; k++)
	{
		for(i=0; i < MAX; i++)
		{
			for(j=0; j < MAX; j++)
			{
		   		sum += a[k][j] * b[j][i];	
			}
			c[k][i] = sum;
			sum = 0;
		}
		
	}
}

void transpose(int a[3][3], int c[3][3])
{
	int i,j;

	for(i = 0 ; i < MAX; i++)
	{
		for(j=0;j< MAX; j++)
		{
			c[i][j] = a[j][i];
		}
	}
}
