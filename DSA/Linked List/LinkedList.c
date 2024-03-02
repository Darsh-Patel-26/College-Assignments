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
        temp=temp->next;
    }
    temp->next = newNode;
}

void insertMiddle(struct Node **head, int data, int index)
{
    struct Node *newNode = initializer(data);
    size++;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *p1 = *head;
    struct Node *p2 = (*head)->next;
    while (--index && p2 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = newNode;
    newNode->next = p2;
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

int deleteLast(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The linked list is empty, nothing to delete.\n");
        return -1;
    }
    struct Node *lastSec = *head;
    struct Node *last = (*head)->next;
    while (last->next != NULL)
    {
        lastSec = lastSec->next;
        last = last->next;
    }
    lastSec->next = NULL;
    int pop = last->data;
    free(last);

    return pop;
}

struct Node *copyLL(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;  
    }
    struct Node *head2 = NULL;  
    struct Node *temp = head;
    while (temp != NULL)
    {
        insertLast(&head2, temp->data);  
        temp = temp->next;
    }

    return head2;
}


int main(int argc, char const *argv[])
{
    struct Node *head = NULL, *head2 = NULL;
    int data, ch;
    
    printf("Welcome to Linked List!!\n");
    printf("1 for inserting at first.\n");
    printf("2 for inserting at last.\n");
    printf("3 for print linked list.\n");
    printf("4 for inserting at index(head has 0 index).\n");
    printf("5 to print size of linked list.\n");
    printf("6 for deleting last node.\n");
    printf("7 for copying linked list.\n");
    printf("0 to exit.\n");

    while(1)
    {
        printf("\nEnter operation to perform : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d", &data);
            insertFirst(&head,data);
            break;

        case 2:
            printf("Enter data to insert : ");
            scanf("%d", &data);
            insertLast(&head,data);
            break;

        case 3:
            printf("Your Linked List is : \n");
            printLL(head);
            break;

        case 4:
            printf("Enter data to insert : ");
            scanf("%d", &data);
            int index;
            printf("Enter index to insert : ");
            scanf("%d",&index);
            insertMiddle(&head,data,index);
            break;

        case 5:
            printf("The size of list is : %d\n",size);
            break;

        case 6:
            printf("%d deleted from linked list.\n",deleteLast(&head));
            printLL(head);
            break;

        case 7:
            head2 = copyLL(head);
            printf("The copied linked list is :\n");
            printLL(head2);
            break;

        case 0:
            printf("Exited Successfully!!\n");
            return 0;

        default:
            printf("Error, Try again!!\n");
            break;
        }
    }
    return 0;
}