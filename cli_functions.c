#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "cli_functions.h"
#include "array_i16.h"

void read_value(const char *message,
    const char *retry_message,
    int16_t *value)
{
    int temp;

    printf("\n%s", message);

    while (scanf("%d", &temp) != 1)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;  // clear input buffer

        printf("\n%s", retry_message);
    }

    *value = (int16_t) temp;
}


bool append_to_array(array_i16 *arr)
{
    int16_t val;

    read_value("Please, provide the value to be appended: ",
        "Please, provide the value to be appended again: ",
        &val
    );

	return append(arr, (int16_t) val);
}

bool search_array(const array_i16 *arr)
{
    int16_t val1;
    ptrdiff_t val2;
    read_value("Please, provide the value to be searched for: ",
        "Provide the value to be searched again: ",
    &val1);

	val2 = idx_of(arr, (int16_t) val1);

	if(val2 == -1)
	{
		return false;
	}

	printf("Value %d is found on the index %zu.\n", val1, (size_t) val2);
    return true;
}

bool delete_from_array(array_i16 *arr)
{
    int16_t val1;
    ptrdiff_t val2;
    read_value("Please, provide the value to be deleted: ",
        "Provide the value to be deleted again: ",
        &val1
    );

    val2 = idx_of(arr, val1);

    if(val2 == -1)
    { 
        return false;
    }

    if(delete_at_idx(arr, (size_t) val2) == false)
    {
        return false;
    }

    printf("The value was successfully deleted.\n");
    return true;
}

bool clear_array(array_i16 *arr)
{
    int16_t val1;
    read_value("Are you sure you want to clear the array? (1 - yes, 0 - no): ",
    "Try again, do you want to clear the array? (1 - yes, 0 - no): ",
    &val1);

	if(val1 == 0) return true;

	arr->length = 0;
    printf("Successfully cleared the array!\n");
    return true;
}

void print_array(const array_i16 *arr)
{
	if(arr == NULL || arr->length == 0) 
	{
		printf("Array is empty!\n");
		return;
	}

	for(size_t i = 0; i < arr->length; i++)
	{
		printf("%d ", arr->items[i]);
	}
}