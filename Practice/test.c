#include <stdio.h>

int main()
{
	char *c = "good";
	char *c1 = NULL;

	while(*c1++ = *c++);
	printf("%s %s",c1,c);
}
