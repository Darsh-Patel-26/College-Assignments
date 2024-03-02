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
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
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
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    newNode->prev = (*head)->prev;
    newNode->next = *head;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
}

void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    if ((*head)->next == *head)
    {
        *head = NULL;
    }
    else
    {
        *head = temp->next;
        (*head)->prev = temp->prev;
        temp->prev->next = *head;
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
    struct Node *temp = (*head)->prev;
    if ((*head)->next == *head)
    {
        *head = NULL;
    }
    else
    {
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
    }
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
    do
    {
        printf("%d<-->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("... (circular)\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;

    int data;
    int ch;

    printf("Welcome to Circular Doubly Linked List!!\n");
    printf("1 for inserting at first.\n");
    printf("2 for inserting at last.\n");
    printf("3 for print linked list.\n");
    printf("4 for peeking head node.\n");
    printf("5 to print size of linked list.\n");
    printf("6 for delete first.\n");
    printf("7 for delete last.\n");
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
        deleteFirst(&head);
        goto loop;

    case 7:
        deleteLast(&head);
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
