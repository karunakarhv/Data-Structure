#include <stdio.h>
#include <stdlib.h>

int noOfDigits(unsigned int num)
{
      
}
void printPositive(unsigned int num1, unsigned int num2, unsigned int result)
{
   int n1= 0, n2=0;
	printf(" %d\n",num1);
	printf("+%d\n",num2);
	n1 = noOfDigits(num1);
	n2 = noOfDigits(num2);
	printf("------\n");
	printf(" %d\n",result);
}

void printNegative(unsigned int num1, unsigned int num2, unsigned int result)
{
	printf("%d",num1);
	printf("-%d",num2);
	printf("------\n");
	printf("%d",result);
}


int main()
{
	unsigned int no_test_cases = 0, num1 = 0, num2 = 0, result = 0;	
        //int operator;
        char ch,operator;

	printf("Enter the Test case:\n");
	scanf("%d",&no_test_cases);
	
	while(no_test_cases--)
	{
		printf("Enter the 1st number:");
		scanf("%d",&num1);
		printf("\n");
		fflush(stdout);
		printf("Enter the operator:");
		scanf(" %c ",&operator);
		printf("\n");
		fflush(stdout);
		printf("Enter the 2nd number:");
		scanf("%d",&num2);
	        printf("\n");
                fflush(stdout);
		switch(operator)
		{
			case '+':
		        printf("Positive\n");
			result = num1 + num2;
			printPositive(num1,num2,result);
			break;
			case '-':
			result = num1 - num2;
			printNegative(num1,num2,result);
			break;
			case '*':
			break;
                        default:
                           printf("Enter the proper operator\n");
                           break;

		}
	}
	
	return 0;
}
