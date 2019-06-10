#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

#define MAXVAL 1000

typedef char Line[80 + 1];

Line values[MAXVAL];	//speichern der Zahlen

int main(int argc, char *argv[])
{

	char buffer[MAXVAL];	//Zwischenspeicher einer Zahl
	FILE *in = stdin;		//speichern der Datei
	char *pointer;			//Pointer auf Buffer

	int valuesCount = 0;

	if (argc == 2)
	{
		in = fopen(argv[1], "r");
		if (!in)
		{
			exit(EXIT_FAILURE);
		}
	}
	
	while(pointer = fgets(buffer, 80, in))
	{
		if (valuesCount == MAXVAL)
		{
			printf("Too many data values\n");
			exit(EXIT_FAILURE);
		}
		
		strcpy(values[valuesCount], pointer);
		valuesCount++;
	}

	for (int i = valuesCount; i; i--)
	{
		printf("%s", values[i-1]);
	}
	
	if (in != stdin)
	{
		fclose(in);
	}

	exit(EXIT_SUCCESS);
}