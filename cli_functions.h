#ifndef CLI_FUNCTIONS_H
#define CLI_FUNCTIONS_H

#include "dynamic_int_array.h"
#include <stdbool.h>

#define APPEND_CODE 'a'
#define SEARCH_CODE 's'
#define DELETE_CODE 'd'
#define PRINT_CODE 'p'
#define CLEAR_CODE 'c'
#define EXIT_CODE 'e'

bool append_to_array(array_i16 *arr);
bool search_array(const array_i16 *arr);
bool delete_from_array(array_i16 *arr);
bool clear_array(array_i16 *arr);
void print_array(const array_i16 *arr);

#endif