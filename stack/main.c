#include "Stack.h"
int main()
{
    Stack* stack = (Stack*)malloc(sizeof(stack));
    stack = InitStack(stack);
    Push(stack,10);
    Push(stack,20);
    Push(stack,30);
    Print(stack);
    return 0;
}