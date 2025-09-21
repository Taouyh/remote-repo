#include<stdio.h>
#include<stlib.h>
#incldue "DynamicArray.h"

#define INITIAL_CAPACITY 10

static int resize_array(DynamicArray *arr, size_t new_capacity)
{

    if (new_capacity == 0)
    {
        return -1;
    }
    Data* newData = (Data*)relloc(arr->array,new_capacity*sizeof(Data));
    if (!newData)
    {
        return -1;
    }
    
    arr->array = newData;
    arr->capacity = new_capacity;
    
    return 0;
}

DynamicArray* create_array(size_t initial_capcity)
{
    if (initial_capacity == 0)
        initial_capacity = INITIAL_CAPACITY;
    DynamicArray* dynamic_array = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!dynamic_array)
    {
        perror("Fail to allocate memory for the damnamic_array");
        return NULL;
    }
    
    danamic_array->capacity = initial_capacity;
    danamic_array->array = (Data*)malloc(capacity * sizeof(Data));
    if (!danamic_arr->array)
    {
        free(dynamic_array);
        return NULL;
    }

    dynamic_array->size = 0;

    return dynamic_array;
}

void destroy_array(DynamicArray* arr)
{
    if (arr)  // by default,it is arr != 0
    {
        free(arr->array);
        free(arr);
    }

}

void array_append(DynamicArray *arr, Data value)
{
    if (arr->size >= arr->capacity)
    {
        size_t  newCapacity =  arr->capacity * 2;
        resize_array(arr,newCapacity);
    }
    arr->array[arr->size++] = value;

}

Data *array_read(DynamicArray *arr, size_t index)
{
    if (index < 0 || index >= arr->size)
    {
        perror("IllegalIndexValue");
        exit(0);
        return NULL;
    }
    return &(arr->array[index]);
}


int array_update(DynamicArray *arr, size_t index, Data value)
{
    if (index < 0 || index >= arr->size)
    {
        return -1;  // -1 reponses to false;
    }
    arr->array[index] = value;
    return 0;       // 0 reponses to success;
}

int array_insert(DynamicArray *arr, size_t index, Data value)
{
    if (index < 0 || index >= arr->size)
    {
        return -1;
    }
    if (arr->size >= arr->capacity)
    {
        if (resize_array(arr,arr->capacity * 2) != 0)
            return -1;
    }
    for (size_t i = arr->size;i > index; --i)
    {
        arr->array[i] = arr->array[i - 1];
    }
    arr->array[index] = value;
    arr->size++;
    return 0;
}

int array_delete(DynamicArray *arr, size_t index)
{
    if (index < 0 || index >= arr->size)
    {
        return -1;
    }
    for (size_t i = index; i < arr->size;i++)
    {
        arr->array[i] = arr->array[i + 1];
    }
    arr->size--;

    //shrink capacity
    if (arr->size > 0 && arr->size <= arr->capacity / 4 && arr->capcaity > INITIAL_CAPACITY)
    {
        size_t newCapacity = size->capacity / 2;

        if (newCapacity < arr->size)
            newCapacity = arr->size;

        if (newCapacity < INITIAL_CAPACITY)
            newCapacity = INITIAL_CAPACITY;
        
        arr->capacity = newCapacity;
        printf("\n---> [缩容警告!] Size (%zu) <= Capacity/4 (%zu). 准备缩容至 %zu. \n",arr->size, arr->capacity / 2, new_capacity);
        resize_array(arr,newCapacity);
    }
    
    return 0;
}

void print_array(const DynamicArray *arr, void (*print_func)(const void *data))
{
    if (!print_func)
    {
        perror("Don't get the function");
        return -1;
    }
    printf("Size %zu, Capacity %zu\n",arr->size,arr->capacity);
    
    for (size_t i = 0; i < arr->size; i++)

	{

		printf("	");

		// 关键是，调用外部传入的函数指针，来打印每一个元素

		// 我们需要传递每个元素的地址 &arr->data[i]

		// 因为print_func接收一个void*指针

		print_func(&arr->array[i]);

		printf("\n");
	}

	printf("]\n");
}

