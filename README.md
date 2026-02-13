# Dynamic Array
An implementation of the int16_t dynamic array (vector), and a showcase of it's functionality in a primitive CLI.
This is my first "serious" project in C.

## Project structure
### Header files
* array_i16.h - contains definition for array_i16 struct as well for all the array handling functions.
* cli_functions.h - contains definitions for CLI helper functions which manage user input, conduct operations on the array and handle errors.
### Implementations 
* main.c - main file, top-level CLI logic and memory handling.
* array_i16.h - contains implementations for array_i16.h functions as well as internal _bool grow_array(array_i16 *arr)_ method, used for reallocating memory when length matches size.
* cli_functions.c - contains implementations for cli_functions.h.

## Documentation
Coming soon...
For now, you can check the files. They contain some useful comments.
