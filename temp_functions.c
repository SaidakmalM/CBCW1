#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "temp_functions.h"

int print_help (void)
{
	printf("Temp statistic application. Please enter key: \n");
	printf("-h for help.\n");
	printf("-f file_name for load this file.\n");
	printf("-m xx statistic for xx month.\n");
	return 0;
}

int one_month_stat(char *name, int MM)
{
	FILE * open;
	int N=6;
	open = fopen(name, "r");
	if (open == NULL)
		return 1;
	int Y,M,D,H,Mt,T;
	int r,i,j=0,aver=0,min=100,max=-100;
	char ch=0;
	while((r=fscanf(open,"%d;%d;%d;%d;%d;%d;",&Y,&M,&D,&H,&Mt,&T))>0)
	{
		if (M == MM)
		{
			if (r<N)
			{
				do
				{
					putchar(ch);
					ch = fgetc(open);
				}
				while (ch != EOF && ch != '\n');
				ch = 0;
				printf("\n");
				j++;
			}
			else
			{
				if (T > max) max = T; 
				if (T < min) min = T; 
				aver += T;
				i++;
			}
		}
	}
	aver = aver/i;
	printf("%5d%6d%8d%8d%9d%9d%9d\n", Y, MM, i, j, aver, min, max);
	fclose(open);
	r=0;i=0;j=0;aver=0;min=100;max=-100;
	return 0;
}

