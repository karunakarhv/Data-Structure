#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validateInput(struct tm *checkInTime ,int testFlag)
{
	int flag = 0;
	if(testFlag == 0)
	{
		if(checkInTime->tm_hour > 24)
		{
			flag = 1;
			printf("Enter Hours less than 24\n");
		}
		else if(checkInTime->tm_hour < 0)
		{
			flag = 1;
			printf("Enter hours greater than or equal to 0\n");
		}
		else if(checkInTime->tm_min > 60)
		{
			flag = 1;
			printf("Enter Minutes less than 60\n");
		}
		else if(checkInTime->tm_sec > 60)
		{
			flag = 1;
			printf("Enter Seconds less than 60\n");	
		}
		else if(checkInTime->tm_sec < 0)
		{
			flag = 1;
			printf("Enter Seconds greater than or equal to 0\n");
		}
		else if(checkInTime->tm_min < 0)
		{
			flag = 1;
			printf("Enter Minutes greater than or equal to 0\n");
		}
	}	
	else if(testFlag == 1)
	{
		if(checkInTime->tm_hour > 12)
		{
			flag = 1;
			printf("Enter Hours less than 24\n");
		}
		else if(checkInTime->tm_hour < 0)
		{
			flag = 1;
			printf("Enter hours greater than or equal to 0\n");
		}
		else if(checkInTime->tm_min > 60)
		{
			flag = 1;
			printf("Enter Minutes less than 60\n");
		}
		else if(checkInTime->tm_sec > 60)
		{
			flag = 1;
			printf("Enter Seconds less than 60\n");	
		}
		else if(checkInTime->tm_sec < 0)
		{
			flag = 1;
			printf("Enter Seconds greater than or equal to 0\n");
		}
		else if(checkInTime->tm_min < 0)
		{
			flag = 1;
			printf("Enter Minutes greater than or equal to 0\n");
		}
	}	
	return flag;
}
int main()
{
	struct tm *checkOutTime;
	struct tm *checkInTime;
	char *buffer;
	unsigned int flag = 0, hour12Format = 0, hour24Format = 0, amOrpm = 0;	
        unsigned int valiflag = 1;

        checkInTime = (struct tm *)malloc(sizeof(struct tm));
        checkOutTime = (struct tm *)malloc(sizeof(struct tm));	
        buffer = (char *) malloc(100);

	while(valiflag == 1)
	{
        	printf("Display 12 hour format?(Press 1:Yes 0:No)");
		scanf("%d",&flag);
                if(flag == 1)
		{
			printf("Enter Check in Time Hour\n");
			scanf("%d",&checkInTime->tm_hour);
			printf("Enter Check in Time Min\n");
			scanf("%d",&checkInTime->tm_min);
			printf("Enter Check in Time Sec\n");
			scanf("%d",&checkInTime->tm_sec);
                        printf("Enter AM(0) or PM(1)?\n");
			scanf("%d",&amOrpm);
        		valiflag = validateInput(checkInTime,flag);
		}
		else if(flag == 0)
		{
			printf("Enter Check in Time Hour\n");
			scanf("%d",&checkInTime->tm_hour);
			printf("Enter Check in Time Min\n");
			scanf("%d",&checkInTime->tm_min);
			printf("Enter Check in Time Sec\n");
			scanf("%d",&checkInTime->tm_sec);
                        printf("Enter AM(0) or PM(1)?\n");
			scanf("%d",&amOrpm);
        		valiflag = validateInput(checkInTime,flag);
			
		}

		if(valiflag == 0)
			break;
		else
		{
			printf("Please enter the Inputs once again\n");
			continue;
		}
 	}
       
	checkOutTime->tm_hour = checkInTime->tm_hour + 9;
	checkOutTime->tm_min = checkInTime->tm_min;
	checkOutTime->tm_sec = checkInTime->tm_sec;

	if(flag == 1)
	{
        	if(checkOutTime->tm_hour > 12)
		{
  			hour12Format = checkOutTime->tm_hour - 12;
		}
		else
		{
			hour12Format = checkOutTime->tm_hour;
		}
		sprintf(buffer,"(Hour:Min:Sec) %d:%d:%d %s",hour12Format,checkOutTime->tm_min, checkOutTime->tm_sec
		        ,(amOrpm==1)?"PM":"AM");
	}
	else
	{
		if(checkOutTime->tm_hour > 24)
		{
			hour24Format = checkOutTime->tm_hour - 24;
		}
		else
			hour24Format = checkOutTime->tm_hour;
		sprintf(buffer,"(Hour:Min:Sec)%d:%d:%d %s",hour24Format,checkOutTime->tm_min, checkOutTime->tm_sec
			,(amOrpm == 1)?"PM":"AM");
	}
	printf("Check Out Time is %s\n",buffer);

	return 0;	
}
