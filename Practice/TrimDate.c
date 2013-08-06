#include <stdio.h>
void TrimDate(char tempStr1[], char tempStr2[], int tempFirst, int tempSecond);
 
int main()
{
        char str1[128] = "Thu, 16 Aug 2012 20:29:36 +500";
        char str2[128] = {0,};
        int firstPos = 5;
        int lastPos = 22;
	TrimDate(str1,str2,firstPos,lastPos);
	printf("String 1 = %s\n",str1);
	printf("String 2 = %s\n",str2);
	
	return 0;
}


void TrimDate(char tempStr1[], char tempStr2[], int tempFirst, int tempSecond)
{
        int counter = 0;
	while(counter != tempFirst)
	{
                printf("Value = %c\n",*tempStr1);
		tempStr1++;
                counter++;
	}
	while(counter != tempSecond)
	{
		*tempStr2 = *tempStr1;
		tempStr1++;
		tempStr2++;
                counter++;
	}
        tempStr2[counter] = '\0';
}

