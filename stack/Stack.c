#include "Stack.h"
Stack* InitStack(Stack *s)
{
    if (!(*s))
        {
            printf("Stack does not exit.\n");
            return NULL;
        }
    (*s) = (Node*)malloc(sizeof(Node));
    (*s)->next = NULL;
    return s;
}

void DestroyStack(Stack *s)
{
    if (!(*s))
    {
        printf("Stack cannot be destroyed ,beacuse it is not exist.\n");
        exit(0);
    }
    //free(*s)
    Node* current = (*s)->next;
    while(current != NULL)
    {
        Node* stack_next = current->next;
        free(current);
        current = stack_next;
    }
    free(s);
}


bool Push(Stack *s,SElemType e)
{
    Node* newData = (Node*)malloc(sizeof(Node));
    newData->data = e;
    if ((*s)->next == NULL)
    {
        (*s)->next = newData;
        newData->next = NULL;
        return 0;
    }

    Node* temp = (*s)->next;
    newData->next = temp;
    (*s)->next = newData;
    return 0;
}

bool Pop(Stack *s,SElemType e)
{
    if (!(*s))
    {
        printf("Stack does not exist.\n");
        exit(0);
    }
    Node* temp = *s;
    e = temp->data;
    (*s) = (*s)->next;
    free(temp);
    return 0;
}

SElemType GetTop(Stack *s,SElemType e)
{
    Node* current = (*s)->next;
    e = current->data;
    return e;
}


void Print(Stack *s)
{
    Node* temp = (*s)->next;
    printf("Stack: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ClearStack(Stack *s)
{
    if ((*s)->next != NULL)
    {
        Node* current = (*s)->next;
        while(current != NULL)
        {
            Node* cnext = current->next;
            free(current);
            current = cnext;
        }
    }
    
}

bool StackEmpty(Stack *s)
{
    return (*s)->next == NULL;
}

int StackLength(Stack *s)
{
    int i = 0;
    Node* current = (*s)->next;
    while(current != NULL)
    {
        current = current->next;
        i++;
    }
    return i;
}
