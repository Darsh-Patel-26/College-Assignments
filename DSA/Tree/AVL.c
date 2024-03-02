#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key, height;
    struct Node *left, *right;
} Node;

Node *construct(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;

    return n;
}

void set(int arr[], int n)
{
    printf("Enter %d elements :\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
}

int max(int a, int b) { return a >= b ? a : b; }

int getHeight(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getBF(Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node *leftRotate(Node *y)
{
    Node *x = y->right;
    Node *t = x->left;

    x->left = y;
    y->right = t;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    Node *t = y->right;

    y->right = x;
    x->left = t;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return construct(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    // Balancer
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBF(root);

    // LL case
    if (bf > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }

    // RR case
    if (bf < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }

    // LR case
    if (bf > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL case
    if (bf < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lDepth = height(root->left);
    int rDepth = height(root->right);

    if (lDepth > rDepth)
    {
        return lDepth + 1;
    }
    return rDepth + 1;
}

Node *inorderPredecessor(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *inorderSuccessor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *delete(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->key == val)
    {
        free(root);
        return NULL;
    }
    if (root->key > val)
    {
        root->left = delete (root->left, val);
    }
    else if (root->key < val)
    {
        root->right = delete (root->right, val);
    }
    else
    {
        if (root->right == NULL)
        {
            Node *inPre = inorderPredecessor(root->left);
            root->key = inPre->key;
            root->left = delete (root->left, inPre->key);
        }
        else if (root->left == NULL)
        {
            Node *inPost = inorderSuccessor(root->right);
            root->key = inPost->key;
            root->right = delete (root->left, inPost->key);
        }
        else
        {
            int lDepth = height(root->left);
            int rDepth = height(root->right);
            if (lDepth <= rDepth)
            {
                Node *inPre = inorderPredecessor(root->left);
                root->key = inPre->key;
                root->left = delete (root->left, inPre->key);
            }
            else
            {
                Node *inPost = inorderSuccessor(root->right);
                root->key = inPost->key;
                root->right = delete (root->right, inPost->key);
            }
        }
    }

    if (root == NULL)
    {
        return NULL;
    }
    // Balancer
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBF(root);

    // LL case
    if (bf > 1 && val < root->left->key)
    {
        return rightRotate(root);
    }

    // RR case
    if (bf < -1 && val > root->right->key)
    {
        return leftRotate(root);
    }

    // LR case
    if (bf > 1 && val > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL case
    if (bf < -1 && val < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *search(Node *root, int key)
{
    if (root == NULL)
    {
        // Key not found or tree is empty
        return NULL;
    }

    if (key == root->key)
    {
        // Key found at the current node
        return root;
    }
    else if (key < root->key)
    {
        // Key is in the left subtree
        return search(root->left, key);
    }
    else
    {
        // Key is in the right subtree
        return search(root->right, key);
    }
}

struct Node *build(struct Node *root, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        root = insert(root,arr[i]);
    }
    printf("BST build succesfully!!\n");
    return root;
}


void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d ", root->key);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d ", root->key);
}

int main()
{
    Node *root = NULL;
    int choice, n, key;
    int val[100];

    printf("\nAVL(Adelson-Velsky, Landis) Tree:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Pre-Order Traversal\n");
    printf("5. In-Order Traversal\n");
    printf("6. Post-Order Traversal\n");
    printf("0. Exit\n");

    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter no. of elements to insert : ");
            scanf("%d",&n);
            set(val,n);
            root = build(root,val,n);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = delete (root, key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            Node *result = search(root, key);
            if (result)
            {
                printf("Key %d found in the tree.\n", key);
            }
            else
            {
                printf("Key %d not found in the tree.\n", key);
            }
            break;
        case 4:
            printf("Pre-Order Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("In-Order Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Post-Order Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 0:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}