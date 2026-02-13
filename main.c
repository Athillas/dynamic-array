#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "array_i16.h"
#include "cli_functions.h"

int main(void)
{
	char inp = '\0';
	array_i16 arr;

	if(!init_array(&arr)) 
	{
		printf("Failed to initialize the array!\nExitting the program...");
		return 1;
	}

	printf("Welcome to the dynamic array test program!\n");
	while(true)
	{

		printf("Please, select the option: [a - append, s- search, d- delete, p- print, c- clear array, e- exit]: ");
		if (scanf(" %c", &inp) != 1)
		{
			printf("Input error.\n");
			continue;
		}
		switch (inp)
		{
			case APPEND_CODE:
				if(!append_to_array(&arr))
				{
					printf("Failed to append the value!\n");
				}
				break;
			case SEARCH_CODE:
				if(arr.length == 0)
					{
						printf("Array is empty, therefore no value can be searched for.\n");
						break;
					}
				if(!search_array(&arr))
				{
					printf("The value wasn't found!\n");
				}
				break;
			case DELETE_CODE:
				if(arr.length == 0)
				{
					printf("Array is empty, therefore no value can be deleted.\n");
					break;
				}

				if(!delete_from_array(&arr))
				{
					printf("The value wasn't found, therefore it cannot be deleted.\n");
				}
				break;
			case CLEAR_CODE:
				if(arr.length == 0)
				{
					printf("Array is empty, therefore no value can be deleted.\n");
					break;
				}

				if(!clear_array(&arr))
				{
					printf("The array couldn't be cleared.\n");
				}
				break;
			case PRINT_CODE:
				print_array(&arr);
				printf("\n");
				break;
			case EXIT_CODE:
				free_array(&arr);
				return 0;
		}
		inp = '\0';
	}

	free_array(&arr);
	return 0;
}