#ifndef DYNAMIC_INT_ARRAY_H
#define DYNAMIC_INT_ARRAY_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int16_t *items;
    size_t size;
    size_t length;
} array_i16;

/*
    Initializes array, sets length to 0,
    size to 8,
    allocates size * sizeof(int16_t) = 8 * 4 = 32 bytes
    of memory for the items.

    Returns 1 if memory allocation was a success, 0 otherwise.
*/
bool init_array(array_i16 *new_arr);

/*
    Appends a int16_t value to the end of the array.
    If array is not big enough, it doubles the size and reallocates memory accordingly,
    then appends the value to the end of the array.
*/
bool append(array_i16 *arr, int16_t val);

/*
    Returns an index of element if it's present in the array. If not, returns -1 
*/
ptrdiff_t idx_of(const array_i16 *arr, const int16_t val);

/*
    Returns a value of the array element at provided index, nullptr if index is out of bounds.
*/
const int16_t* arr_at_idx(const array_i16 *arr, const size_t idx); 

/*
    Returns 1 if deletion at idx succeeds, 0 if index is out of bounds or array is empty
*/
bool delete_at_idx(array_i16 *arr, const size_t idx);

/*
    Deallocates memory taken by array items.
*/
void free_array(array_i16 *arr);

#endif