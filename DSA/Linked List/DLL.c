#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
int size = 0;

struct Node *initializer(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
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
    newNode->next = *head;
    (*head)->prev = newNode;
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
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtIndex(struct Node **head, int data, int index)
{
    if (index < 0 || index > size)
    {
        printf("Invalid index for insertion.\n");
        return;
    }
    if (index == 0)
    {
        insertFirst(head, data);
        return;
    }
    if (index == size)
    {
        insertLast(head, data);
        return;
    }
    struct Node *newNode = initializer(data);
    struct Node *temp = *head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    size++;
}

void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
    size--;
}

void deleteLast(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        size--;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
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
    printf("NULL<--");
    while (temp != NULL)
    {
        printf("%d<-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;

    int data;
    int ch;

    printf("Welcome to Doubly Linked List!!\n");
    printf("1 for inserting at first.\n");
    printf("2 for inserting at last.\n");
    printf("3 for print linked list.\n");
    printf("4 for peeking head node.\n");
    printf("5 to print size of linked list.\n");
    printf("6 for inserting at index.\n");
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
        if (head)
        {
            printf("The head node contains : %d\n", head->data);
        }
        else
        {
            printf("The list is empty.\n");
        }
        goto loop;

    case 5:
        printf("The size of list is : %d\n", size);
        goto loop;

    case 6:
        printf("Enter data to insert : ");
        scanf("%d", &data);
        int index;
        printf("Enter index to insert : ");
        scanf("%d",&index);
        insertAtIndex(&head, data, index);
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
