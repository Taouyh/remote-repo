#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

void printData(const void* data)
{
    const Student* s_ptr = (const Student*)data;
    printf("Student {id:%d name:\"%s\"}\n",s_ptr->id,s_ptr->name);
}
int main()
{
    printf("--------Examine the Student Dynamic Array--------\n");
    DynamicArray* student_list = create_array(2);
    Student s1 = {10,"John"};
    Student s2 = {20, "Alex"}
    array_append(student_list,s1);
    array_append(student_list,s2);

    printf("Print Student List!");
    print_func(student_list,&printData);

    destroy_array(student_list);



    // 为了运行这个测试，你需要临时将 DynamicArray.h 中的
    // typedef Student Data; 改回 typedef int Data; 然后重新编译
    /*
    DynamicArray* number_list = create_array(5);
    array_append(number_list, 10);
    array_append(number_list, 20);
    array_append(number_list, 30);

    // 同样调用那个万能的 print_array，但这次把“如何打印整数”的函数传给它！
    printf("打印数字列表：\n");
    print_array(number_list, &print_int);

    destroy_array(number_list);
    */
    return 0;
}