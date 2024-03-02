#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LoopNode
{
    int data;
    struct LoopNode *next;
} LoopNode;

LoopNode *hare;
LoopNode *turtle;

bool detectLoop(LoopNode *head)
{
    hare = head;
    turtle = head;

    while (hare != NULL && hare->next != NULL)
    {
        turtle = turtle->next;
        hare = hare->next->next;

        if (hare == turtle)
        {
            return true;
        }
    }
    return false;
}

void removeLoop(LoopNode **head)
{
    if (!detectLoop(*head))
    {
        printf("The list does not contain loops!!\n");
        return;
    }

    printf("Loop detected!!\n");
    turtle = *head;
    while (turtle->next != hare->next)
    {
        turtle = turtle->next;
        hare = hare->next;
    }

    hare->next = NULL;
    printf("Loop destroyed!!\n");
}

void display(LoopNode *head)
{
    if (head == NULL)
    {
        printf("The List is empty!\n\n");
        return;
    }
    LoopNode *curr = head;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n\n");
}

LoopNode *createNode(int data)
{
    LoopNode *newNode = (LoopNode *)malloc(sizeof(LoopNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void linkNodes(LoopNode **nodes, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[count - 1]->next = nodes[0];
}

int main()
{
    LoopNode *nodes[5];

    for (int i = 0; i < 5; i++)
    {
        nodes[i] = createNode((i + 1) * 10);
    }

    linkNodes(nodes, 5);

    LoopNode *head = nodes[0];

    removeLoop(&head);
    display(head);

    LoopNode *nodes1[5];

    for (int i = 0; i < 5; i++)
    {
        nodes1[i] = createNode((i + 1) * 10);
    }

    linkNodes(nodes1, 5);

    LoopNode *head1 = nodes1[0];

    removeLoop(&head1);
    display(head1);

    return 0;
}
