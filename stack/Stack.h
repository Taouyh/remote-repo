#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int SElemType;

typedef struct 
{
    SElemType data;
    struct Node* next;
}Node, *LinkList;

typedef LinkList Stack;

typedef struct 
{
    Node* base;
    Node* top;
    int stacksize;
}SqStack;


Stack* InitStack(Stack *s);

void DestroyStack(Stack *s);

void ClearStack(Stack *s);

void StackTraverse(Stack s,void(*visit)(SElemType));

bool StackEmpty(Stack *s);

int StackLength(Stack *s);

SElemType GetTop(Stack *s,SElemType e);

bool Push(Stack *s,SElemType e);

bool Pop(Stack *s,SElemType e);

void visit(SElemType e);

void Print(Stack *s);
