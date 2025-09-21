#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int value;
    Node* next;
}Node;
Node* createNode(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node)
    {
        perror("Fail to allocate memory for the node");
        return NULL;
    }

    node -> value = value;
    node ->next = NULL;

    return node;
}

void list_append(Node** headRef, int data)
{
    Node* node = createNode(data);
    if (node == NULL)
    {
        return -1;
    }
    if (*headRef == NULL)
    {
        *headRef = node;
        return 0;
    }
    Node* temp = *headRef;
    while(temp ->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;

}

void prependNode(Node** headRef, int data)
{
    Node* node = createNode(data);
    if (node == NULL)
    {
        perror("Fail to allocate memory for the node");
        return -1;
    }
    if (*headRef == NULL)
    {
        *headRef = node;
        return 0;
    }
    node->next = *headRef;
    *headRef = node;

}

void printList(Node* head)
{
    Node* curent = head;

    printf("The recent list:");

    while(current != NULL)
    {
        printf("%d ",current->value);
        current = current->next;
    }

    printf("\n");

}

Node* findNode(Node* head, int data)
{
    Node* current = head;
    while(current != NULL)
    {
        if (current -> value == data)
            return current;

        current = current->next;
    }
    return NULL;
}

void updateNode(Node* head, int oldData, int newData)
{
    Node* target = findNode(head,oldData);
    if (target != NULL)
    {
        target->value = newData;
        printf("The oldData %d has been upgraded to the newData %d",oldData,newData);

    }
    else
    {
        printf("Not find it");
    }

}

void deleteNode(Node** headRef, int data)
{
    Node* temp = *headRef;
    Node* prev = NULL;
    
    // delete head Node
    if (temp != NULL && temp->value = data)
    {
        *headRef = temp->next;
        free(temp);
        return 0;
    }

    //delete last or middle Node
    while(temp != NULL && temp->value = data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return ;
    
    prev->next = temp->next;
    free(temp);

    
}
void list_free(Node** headRef)
{
    if (*headRef == NULL) return;
    Node* current = *headRef;
    Node* nextNode;
    while(current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *headRef = NULL;
}

int main()
{
    Node* head = NULL;
    //Examenation

    // ...
    return 0;
}