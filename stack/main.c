#include "Stack.h"
int main()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack = InitStack(stack);
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    Print(stack);
    printf("Stack Length: %d\n", StackLength(stack));
    SElemType e = 0;
    printf("Top: %d\n",GetTop(stack,e));
    SElemType delete_value = 0;
    Pop(stack,&delete_value);
    printf("Delete_value: %d\n",delete_value);
    Print(stack);
    printf("Stack Length: %d\n",StackLength(stack));
    printf("Empty the stack:\n");
    ClearStack(stack);
    printf("Stack Length: %d\n", StackLength(stack));
    Print(stack);
    return 0;
}