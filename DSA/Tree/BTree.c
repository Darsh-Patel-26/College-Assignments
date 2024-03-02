#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define MIN 2

struct BTreeNode
{
    int key[MAX + 1], count;
    struct BTreeNode *next[MAX + 1];
};

struct BTreeNode *root;

// Create a node
struct BTreeNode *Construct(int val, struct BTreeNode *child)
{
    struct BTreeNode *newNode;
    newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->key[1] = val;
    newNode->count = 1;
    newNode->next[0] = root;
    newNode->next[1] = child;
    return newNode;
}

// Insert node
void insertNode(int val, int pos, struct BTreeNode *node, struct BTreeNode *child)
{
    int j = node->count;
    while (j > pos)
    {
        node->key[j + 1] = node->key[j];
        node->next[j + 1] = node->next[j];
        j--;
    }
    node->key[j + 1] = val;
    node->next[j + 1] = child;
    node->count++;
}

// Split node
void splitNode(int val, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode)
{
    int median, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    j = median + 1;
    while (j <= MAX)
    {
        (*newNode)->key[j - median] = node->key[j];
        (*newNode)->next[j - median] = node->next[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN)
    {
        insertNode(val, pos, node, child);
    }
    else
    {
        insertNode(val, pos - median, *newNode, child);
    }
    *pval = node->key[node->count];
    (*newNode)->next[0] = node->next[node->count];
    node->count--;
}

// Set the value
int setValue(int val, int *pval, struct BTreeNode *node, struct BTreeNode **child)
{
    int pos;
    if (!node)
    {
        *pval = val;
        *child = NULL;
        return 1;
    }

    if (val < node->key[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = node->count; (val < node->key[pos] && pos > 1); pos--);
        if (val == node->key[pos])
        {
            printf("Duplicates are not permitted\n");
            return 0;
        }
    }
    if (setValue(val, pval, node->next[pos], child))
    {
        if (node->count < MAX)
        {
            insertNode(*pval, pos, node, *child);
        }
        else
        {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

// Insert the value
void insert(int val)
{
    int flag, i;
    struct BTreeNode *child;

    flag = setValue(val, &i, root, &child);
    if (flag)
        root = Construct(i, child);
}

// Search node
void search(int val, int *pos, struct BTreeNode *myNode)
{
    if (!myNode)
    {
        return;
    }

    if (val < myNode->key[1])
    {
        *pos = 0;
    }
    else
    {
        for (*pos = myNode->count; (val < myNode->key[*pos] && *pos > 1); (*pos)--)
            ;
        if (val == myNode->key[*pos])
        {
            printf("%d is found", val);
            return;
        }
    }
    search(val, pos, myNode->next[*pos]);

    return;
}

// Traverse then nodes
void traversal(struct BTreeNode *myNode)
{
    int i;
    if (myNode)
    {
        for (i = 0; i < myNode->count; i++)
        {
            traversal(myNode->next[i]);
            printf("%d ", myNode->key[i + 1]);
        }
        traversal(myNode->next[i]);
    }
}

// Delete a node
void deleteNode(int val, struct BTreeNode *myNode)
{
    int pos;

    if (!myNode)
    {
        printf("%d not found\n", val);
        return;
    }

    if (val < myNode->key[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = myNode->count; (val < myNode->key[pos] && pos > 1); pos--)
            ;

        if (val == myNode->key[pos])
        {
            if (myNode->next[pos - 1])
            {
                struct BTreeNode *predecessor = myNode->next[pos - 1];
                while (predecessor->next[predecessor->count])
                    predecessor = predecessor->next[predecessor->count];
                myNode->key[pos] = predecessor->key[predecessor->count];
                deleteNode(myNode->key[pos], myNode->next[pos - 1]);
            }
            else if (myNode->next[pos])
            {
                struct BTreeNode *successor = myNode->next[pos];
                while (successor->next[0])
                    successor = successor->next[0];
                myNode->key[pos] = successor->key[1];
                deleteNode(myNode->key[pos], myNode->next[pos]);
            }
            else
            {
                for (int i = pos; i < myNode->count; i++)
                {
                    myNode->key[i] = myNode->key[i + 1];
                    myNode->next[i] = myNode->next[i + 1];
                }
                myNode->count--;
            }
            return;
        }
    }

    deleteNode(val, myNode->next[pos]);
}

int main()
{
    int val, ch;

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Traverse\n");
    printf("0. Exit\n");

    while (1)
    {
        printf("\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            deleteNode(val, root);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(val, &ch, root);
            if (ch == 0)
                printf("%d not found\n", val);
            break;
        case 4:
            printf("Tree traversal: ");
            traversal(root);
            printf("\n");
            break;
        case 0:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
