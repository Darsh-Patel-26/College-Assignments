#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *next;
};

int n;

void setArr(int arr[])
{
    printf("Enter %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

struct Node *constructor(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    return newNode;
}

void insertAtHead(int key, struct Node **head)
{
    struct Node *newNode = constructor(key);
    if (*head == NULL)
    {
        *head = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

void insert(int key, struct Node **head)
{
    struct Node *newNode = constructor(key);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d->", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}

void Build(struct Node **head)
{
    printf("Enter No. of elements : ");
    scanf("%d", &n);
    int arr[n];
    setArr(arr);
    for (int i = 0; i < n; i++)
    {
        insert(arr[i], head);
    }
}

struct Node *findMid(struct Node *head)
{
    struct Node *turtle = head;
    struct Node *hare = head->next;
    while (hare != NULL && hare->next != NULL)
    {
        turtle = turtle->next;
        hare = hare->next->next;
    }
    return turtle;
}

struct Node *Merge(struct Node *left, struct Node *right)
{
    if (!left)
    {
        return right;
    }
    if (!right)
    {
        return left;
    }
    struct Node *a = constructor(-1);
    struct Node *temp = a;
    while (left && right)
    {
        if (left->key < right->key)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    struct Node* tem = a;
    a = a->next;
    free(tem);
    return a;
}

struct Node *MergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *mid = findMid(head);

    struct Node *left = head;
    struct Node *right = mid->next;
    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    struct Node *result = Merge(left, right);

    return result;
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    Build(&head);

    display(head);

    head = MergeSort(head);

    display(head);

    return 0;
}