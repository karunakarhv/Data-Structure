#include <stdio.h>
#include <math.h>

#define MAX 3

void create(int [3][3]);
void display(int [3][3]);
void matadd(int [3][3], int [3][3], int [3][3]);
void matmul(int [3][3], int [3][3], int [3][3]);
void transpose(int [3][3], int [3][3]);
int determinant(int [3][3]);
int isortho(int [3][3]);

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

	printf("Determinant of matrix:");
	printf("%d\n",determinant(a));

	printf("Is matrix Orthogonal? %s\n",( isortho(a) ==1 )?"true":"false");

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

int determinant(int mat[3][3])
{
	int sum,i,j,k,p;
	sum =0;j=1;k=MAX-1;

	for(i=0;i < MAX;i++)
	{
		p = pow(-1,i);
		if(i == MAX -1)
			k = 1;
		sum = sum + (mat[0][i] * (mat[1][j]*mat[2][k] - mat[2][j]*mat[1][k])) * p;
		
		j = 0;
	}
	return sum;
}

int isortho(int mat[3][3])
{
	//1.Transpose the given matrix
	//2.Multiply the matrix with the transposed matrix
	//3.Check the resultant matrix is an Identity matrix

	int m1[3][3], m2[3][3], i;
	transpose(mat,m1);

	matmul(mat,m1,m2);

	for(i=0;i<MAX;i++)
	{
		if(m2[i][i] == 1)
			continue;
		else
			break;
	}
	
	if(i == MAX)
		return 1;
	else
		return 0;
}
