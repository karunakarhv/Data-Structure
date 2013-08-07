#include <stdio.h>
#include <stdlib.h>

//Merging of Arrays involve two steps
//1.Sorting the arrays to be merged.
//2.Adding the sorted elements of both arrays
//to a new array in a sorted order.
#define MAX1 5
#define MAX2 7

int *array;
int *create(int);
void sort(int *, int);
void display(int *, int);
int *merge(int *, int *);

int main()
{
	int *a, *b, *c;

	printf("Enter Elements for first array\n");
	a = create(MAX1);
	
	printf("Enter Elements for second array\n");
	b = create(MAX2);

	sort(a,MAX1);
	sort(b,MAX2);

	printf("First Array\n");
	display(a,MAX1);
	printf("Second Array\n");
	display(b,MAX2);

	printf("\n After Merging:\n");
	c = merge(a,b);
	display(c, MAX1+MAX2);

	return 0;
}

int *create(int size)
{
	int *arr, i;
	arr = (int *) malloc( sizeof(int)* size);
	
	for(i = 0; i < size ; i++)
	{	
		printf("Enter the element no.%d:",i+1);
			scanf("%d",&arr[i]);
	}

	return arr;
}

void sort(int *arr, int size)
{
	int i, temp, j;
	//Bubble Sort
	for(i=0; i < size ; i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]> arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}	
	}
}

void display(int *arr, int size)
{
	int i;
	printf("\n");
	for(i=0; i < size; i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

int *merge(int *a , int *b)
{
	int *arr;
	int i,k,j;
	int size = MAX1 + MAX2;
	arr = (int *)malloc(sizeof(int) * (size));
	
	for(k=0,j=0,i=0;i<=size;i++)
        {
		if(a[k] < b[j])
		{
			arr[i] = a[k];
			k++;
			if(k >= MAX1)
			{
				for(i++;j<MAX2;j++,i++)
					arr[i] = b[j];
			}
		}
		else
		{
			arr[i] = b[j];
			j++;
			if(j >= MAX2)
			{
				for(i++;k<MAX1;k++,i++)
					arr[i] = a[k];
			}
		}
	}

	return arr;
}
