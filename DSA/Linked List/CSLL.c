#include <stdio.h>
#include <stdlib.h>

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
    newNode->next = newNode; // Point to itself initially
    return newNode;
}

void insertFirst(struct Node **head, int data)
{
    struct Node *newNode = initializer(data);
    size++;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node **head, int data)
{
    struct Node *newNode = initializer(data);
    size++;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void printLL(struct Node *head)
{
    if (head == NULL)
    {
        printf("The Linked list is empty!!\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("... (circular)\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;

    int data;
    int ch;

    printf("Welcome to Circular Singly Linked List!!\n");
    printf("1 for inserting at first.\n");
    printf("2 for inserting at last.\n");
    printf("3 for print linked list.\n");
    printf("4 to print size of linked list.\n");
    printf("0 to exit.\n");

loop:
    printf("\nEnter operation to perform : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter data to insert : ");
        scanf("%d", &data);
        insertFirst(&head, data);
        goto loop;

    case 2:
        printf("Enter data to insert : ");
        scanf("%d", &data);
        insertLast(&head, data);
        goto loop;

    case 3:
        printf("Your Linked List is : \n");
        printLL(head);
        goto loop;

    case 4:
        printf("The size of list is : %d\n", size);
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
