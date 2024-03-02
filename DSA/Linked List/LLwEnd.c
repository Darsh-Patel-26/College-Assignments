#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int size = 0;

struct Node *initializer(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(struct Node **head, struct Node **end, int data)
{
    struct Node *newNode = initializer(data);
    size++;
    if (*head == NULL)
    {
        *head = newNode;
        *end = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node **head,struct Node **end, int data)
{
    if (*end == NULL && *head == NULL)
    {
        insertFirst(head,end,data);
        return;
    }
    struct Node *newNode = initializer(data);
    (*end)->next = newNode;
    *end = newNode;
    size++;
}

void deleteFirst(struct Node **head, struct Node **end)
{
    if (*head == NULL && *end == NULL)
    {
        printf("The list is empty nothing to delete!!\n");
        return;
    }
    if ((*head)->next == NULL && (*end)->next == NULL)
    {
        free(*head);
        *head = NULL;
        *end = NULL;
        size--;
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    size--;
}

void deleteLast(struct Node **head, struct Node **end)
{
    if (*head == NULL && *end == NULL)
    {
        printf("The list is empty nothing to delete!!\n");
        return;
    }
    if ((*head)->next == NULL && (*end)->next == NULL)
    {
        free(*head);
        *head = NULL;
        *end = NULL;
        size--;
        return;
    }
    struct Node *lastSec = *head;
    while (lastSec->next!=*end)
    {
        lastSec = lastSec->next;
    }
    free(*end);
    *end = lastSec;
    (*end)->next = NULL;
    size--;
}

void printLL(struct Node *head)
{
    if (head == NULL)
    {
        printf("The Linked list is empty!!\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    struct Node *end = NULL;

    int data;
    int ch;
    
    printf("Welcome to Linked List!!\n");
    printf("1 for inserting at first.\n");
    printf("2 for inserting at last.\n");
    printf("3 for print linked list.\n");
    printf("4 to delete first node.\n");
    printf("5 to delete last node.\n");
    printf("6 for peeking head node.\n");
    printf("7 for peeking end node.\n");
    printf("8 for printing size of linked list.\n");
    printf("0 to exit.\n");

loop:
    printf("\nEnter operation to perform : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter data to insert : ");
        scanf("%d", &data);
        insertFirst(&head,&end,data);
        goto loop;

    case 2:
        printf("Enter data to insert : ");
        scanf("%d", &data);
        insertLast(&head,&end,data);
        goto loop;

    case 3:
        printf("Your Linked List is : \n");
        printLL(head);
        goto loop;

    case 4:
        deleteFirst(&head,&end);
        goto loop;
    
    case 5:
        deleteLast(&head,&end);
        goto loop;

    case 6:
        printf("The head node contains : %d\n",head->data);
        goto loop;

    case 7:
        printf("The end node contains : %d\n",end->data);
        goto loop;

    case 8:
        printf("The size of list is : %d\n",size);
        goto loop;
    
    case 0:
        printf("Exited Successfully!!\n");
        break;

    default:
        printf("Error, Try again!!\n");
        goto loop;
    }
    return 0;
}