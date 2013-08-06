#include <stdio.h>
#include <string.h>

#if 0
enum
{
	FALSE=0
	TRUE
}BOOL;
#endif

int substr(char *origStr, char *subStr)
{
	int len1 = strlen(origStr);
	int len2 = strlen(subStr);
	int indexOrigStr = 0, indexSubstr = 0;

	for(indexOrigStr = 0; indexOrigStr < len1; indexOrigStr++)
	{
		if(indexSubstr == len2) return (indexOrigStr - indexSubstr);

		for(indexSubstr = 0; indexSubstr < len2; indexSubstr++)
		{
			if(origStr[indexOrigStr] == subStr[indexSubstr])
			{
				indexOrigStr++;
				continue;
			}
			else
				break;
		}
	}

	if(indexOrigStr == len1) 
	{
		indexOrigStr = 0;
		printf("Not Found");
	}
	return indexOrigStr;

}

int main()
{
	char *str1 = "karunakar";
	char *str2 = "ar";
	int index = substr(str1,str2);
	printf("Position: %d\n",index);
	return 0;
}
