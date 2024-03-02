#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *initialize(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Recursive Traversal
void preOrderRecursive(struct Node *root)
{
    if (root)
    {
        printf(" %d ", root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}

void inOrderRecursive(struct Node *root)
{
    if (root)
    {
        inOrderRecursive(root->left);
        printf(" %d ", root->data);
        inOrderRecursive(root->right);
    }
}

void postOrderRecursive(struct Node *root)
{
    if (root)
    {
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        printf(" %d ", root->data);
    }
}

// Stack code
struct Node *stack[MAX_SIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX_SIZE - 1;
}

void push(struct Node *root)
{
    if (isFull())
    {
        return;
    }
    stack[++top] = root;
}

struct Node *pop()
{
    if (isEmpty())
    {
        return NULL;
    }
    return stack[top--];
}

struct Node *peek()
{
    return stack[top];
}

// Iterative Traversals
void preOrderIterative(struct Node *root)
{
    while (1)
    {
        while (root != NULL)
        {
            printf(" %d ", root->data);
            push(root);
            root = root->left;
        }
        if (isEmpty())
        {
            break;
        }
        root = pop();
        root = root->right;
    }
}

void inOrderIterative(struct Node *root)
{
    while (1)
    {
        while (root != NULL)
        {
            push(root);
            root = root->left;
        }
        if (isEmpty())
        {
            break;
        }
        root = pop();
        printf(" %d ", root->data);
        root = root->right;
    }
}

void postOrderIterative(struct Node *root)
{
    struct Node *prev = NULL;
    do
    {
        while (root != NULL)
        {
            push(root);
            root = root->left;
        }
        while (root == NULL && !isEmpty())
        {
            root = peek();
            if (root->right == NULL || root->right == prev)
            {
                printf(" %d ", root->data);
                pop();
                prev = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!isEmpty());
}

// Queue code
struct Node *queue[MAX_SIZE];
int front = - 1, rear = - 1;

int isEmptyQ()
{
    return front == - 1 && rear == - 1;
}

int isFullQ()
{
    return rear == MAX_SIZE - 1;
}

void enQueue(struct Node *root)
{
    if (isFullQ())
    {
        front = rear = -1;
        return;
    }
    if (isEmptyQ())
    {
        front++;
    }
    queue[++rear] = root;
}

struct Node *deQueue()
{
    if (isEmptyQ())
    {
        return NULL;
    }
    return queue[front++];
}

void deleteQ()
{
    front = rear = -1;
}

void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct Node *temp = NULL;
    enQueue(root);
    while (!isEmptyQ())
    {
        temp = deQueue();
        printf(" %d ",temp->data);
        if (temp->left != NULL)
        {
            enQueue(temp->left);
        }
        if (temp->right != NULL)
        {
            enQueue(temp->right);
        }
    }
    deleteQ();
}

void main()
{
    struct Node *root = initialize(4);
    root->left = initialize(2);
    root->right = initialize(6);
    root->left->left = initialize(1);
    root->left->right = initialize(3);
    root->right->left = initialize(5);
    root->right->right = initialize(7);

    printf("\n# Recursive Traversal :\n\n");
    printf("The Pre-Order is :\t");
    preOrderRecursive(root);
    printf("\n");
    printf("The In-Order is :\t");
    inOrderRecursive(root);
    printf("\n");
    printf("The Post-Order is :\t");
    postOrderRecursive(root);
    printf("\n\n");

    printf("\n# Iterative Traversal :\n\n");
    printf("The Pre-Order is :\t");
    preOrderIterative(root);
    printf("\n");
    printf("The In-Order is :\t");
    inOrderIterative(root);
    printf("\n");
    printf("The Post-Order is :\t");
    postOrderIterative(root);
    printf("\n\n");

    printf("# Level-Order Traversal :\n");
    levelOrderTraversal(root);
}