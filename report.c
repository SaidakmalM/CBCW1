#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "temp_functions.h"

int main(int argc, char *argv[])
{
	if((strcmp(argv[1], "-h")) == 0)
	{
		printf("Info about programm:\n");
		print_help ();
	}
	if((strcmp(argv[1], "-f")) == 0)
		{if (argv[3] != 0)
			{
				if((strcmp(argv[3], "-m")) == 0) 
					{
						if ((strcmp(argv[4], "(null)")) == 0)
							printf("there is no month \n");
						else 
						{
							printf("count stat for month %s\n", argv[4]);
							printf("Year  Month NuValue ErValue MonthAver MonthMin MonthMax\n");
							one_month_stat(argv[2], atoi(argv[4]));
						}
					}
			}
			else 
			{
				printf("count stat for year\n");
				printf("Year  Month NuValue ErValue MonthAvg MonthMin MonthMax\n");
				for (int k=1; k<13; k++) one_month_stat(argv[2], k);
			}
		}
	return 0;
}
