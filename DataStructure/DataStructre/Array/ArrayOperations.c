#include <stdio.h>

#define MAX 5

void insert(int *, int pos, int data);
void delete(int *, int pos);
void reverse(int *);
void search(int *, int key);
void display(int *);

int main()
{
	int array[5];
	
	insert(array, 1, 11);
	insert(array, 2, 10);
	insert(array, 3, 9);
	insert(array, 4, 8);
	insert(array, 8, 7);

	printf("\nElements of Array:");
	display(array);

        //Delete the data at Position
	delete(array, 1);
	display(array);

	//Reverse the array
	reverse(array);
	display(array);

	search(array, 10);
}

void insert(int *array, int pos, int data)
{
	int i;
	for(i = MAX - 1; i >= pos; i--)
		array[i] = array[i-1];
	array[i] = data;
}

void display(int *array)
{
	int i;

	printf("\n");
	for(i = 0; i < MAX; i++)
		printf("%d:%d\n",i,array[i]);

	printf("\n");
}

void delete(int *array, int pos)
{
	int i;
	//Moved the array to left side
	//And at the last position inserted zero.
	for(i= pos; i < MAX; i++)
		array[i-1] = array[i];

	array[i-1] = 0;	
}

void reverse(int *array)
{
	int i;
	//Dividing the array and swapping the last 
        //contents with first contents and then on
	for(i = 0; i < MAX/2; i++)
	{
		int temp = array[i];
		array[i] = array[MAX - 1 - i];
		array[MAX - 1 - i] = temp;
	}
}

void search(int *array , int key)
{
	int i;
	for(i = 0; i < MAX ; i++)
	{
		if(array[i] == key)
		{
			printf("\nElement is found at %d position %d\n",i,key);
			return;
		}
	}
	printf("Element not found\n");
	return ;
}
