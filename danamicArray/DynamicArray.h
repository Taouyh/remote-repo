#pragma once
#incude<stddef.h>
typedef struct
{
    int id;
    char name[50];
}Student;

typedef Student Data;

typedef struct
{

    Data* array;
    size_t size;
    size_t capacity;
}DynamicArray;

DynamicArray* create_array(size_t initial_capcity);

void destroy_array(DynamicArray* arr);

void array_append(DynamicArray *arr, Data value);

Data *array_read(DynamicArray *arr, size_t index);

int array_update(DynamicArray *arr, size_t index, Data value);

int array_insert(DynamicArray *arr, size_t index, Data value);

int array_delete(DynamicArray *arr, size_t index);

void print_array(const DynamicArray *arr, void (*print_func)(const void *data));

