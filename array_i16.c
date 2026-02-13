#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "array_i16.h"

/*
    Initializes array, sets length to 0,
    size to 8,
    allocates size * sizeof(int16_t) = 8 * 4 = 32 bytes
    of memory for the items.

    Returns 1 if memory allocation was a success, 0 otherwise.
*/
bool init_array(array_i16 *new_arr)
{
    if(new_arr == NULL) return false;

    new_arr->size = 8;
    new_arr->length = 0;
    new_arr->items = malloc(new_arr->size * sizeof(*new_arr->items));
    if(new_arr->items == NULL)
        return 0;
    return 1;
}

/*  Is a local function.
    Reallocates memory for the items of array with double the size. If successfull, return true.
    If array is empty or it fails to do so, it returns false.
*/
bool grow_array(array_i16 *arr)
{
    if(arr == NULL) return false;

    if(arr->size > SIZE_MAX / 2)
        return false;

    size_t new_size = arr->size * 2;
    int16_t *new_items = realloc(arr->items, new_size * sizeof(*arr->items));

    if(new_items == NULL)
        return false;

    arr->items = new_items;
    arr->size = new_size;
    return true;
}

/*
    Appends a int16_t value to the end of the array.
    If array is not big enough, it doubles the size and reallocates memory accordingly,
    then appends the value to the end of the array.
*/
bool append(array_i16 *arr, const int16_t val)
{
    if(arr == NULL || arr->items == NULL) return false;
    
    if((arr->length == arr->size) && (!grow_array(arr))) return false;

    arr->items[arr->length++] = val;
    return true;
}

/*
    Returns an index of element if it's present in the array. If not, returns -1 
*/
ptrdiff_t idx_of(const array_i16 *arr, const int16_t val)
{
    if(arr == NULL) return -1;
    for(size_t i = 0; i < arr->length; i++)
    {
        if(arr->items[i] == val) return (ptrdiff_t) i;
    }
    return -1;
}

/*
    Returns a pointer to the array element at provided index, NULL if index is out of bounds.
*/
const int16_t* arr_at_idx(const array_i16 *arr, const size_t idx)
{
    if(arr == NULL || idx >= arr->length) return NULL;

    return &(arr->items[idx]);
}

/*
    Returns 1 if deletion at idx succeeds, 0 if index is out of bounds or array is empty.
*/
bool delete_at_idx(array_i16 *arr, size_t idx)
{
    if(arr == NULL || arr->items == NULL) return false;
    if(arr->length == 0 || idx >= arr->length) return false;

    for(size_t i = idx; i < arr->length - 1; i++)
    {
        arr->items[i] = arr->items[i + 1];
    }

    arr->length--;

    return true;
}

/*
    Deallocates memory taken by array items if array and array items are not NULL.
*/
void free_array(array_i16 *arr)
{
    if(arr == NULL || arr->items == NULL) return;
    free(arr->items);
    arr->items = NULL;
    arr->size = arr->length = 0;
}