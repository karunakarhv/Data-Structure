/*
	Lat - Temp
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0,max = 0;
	int array[180];
	float averageSouthHemisphere = 0,averageNorthHemisphere = 0;
        int *p = &(array[90]);	
	for(i=-90;i<=90;i++)
	{	
        		p[i] = i;
		printf("Lat:%d, Temp:%d\n",i,p[i]);
	}
	
	for(i=-90;i<90;i++)
		printf("Latitude:%d\tTemp:%d\n",i,p[i]);

	for(i= -90;i<= 90;i++)
		if(p[i] == 0)
			printf("NO DATA\n");

	//Average temperature
	for(i = -90; i <= -1; i++)
		averageSouthHemisphere += p[i]; 

	for(i = 1 ; i <= 90 ; i++)
		averageNorthHemisphere += p[i];

	averageSouthHemisphere = averageSouthHemisphere/90;
	averageNorthHemisphere = averageNorthHemisphere/90;

	printf("Average Northern Hemisphere Temp: %f\n",averageNorthHemisphere);
	printf("Average Southern Hemisphere Temp: %f\n",averageSouthHemisphere);

	if(averageNorthHemisphere > averageSouthHemisphere)
		printf("Northern Hemisphere is warmer\n");
	else
		printf("Southern Hemisphere is warmer\n");

	
	return 0;
}
