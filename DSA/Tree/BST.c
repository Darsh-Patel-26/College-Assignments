#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *initializer(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void set(int arr[], int n)
{
    printf("Enter %d elements :\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void preorder(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
}


void inorder(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
}

int height(struct Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lDepth = height(root->left);
    int rDepth = height(root->right);

    if (lDepth > rDepth)
    {
        return lDepth+1;
    }
    return rDepth+1;
}

struct Node* inorderPredecessor(struct Node* root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node* inorderSuccessor(struct Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node *insert(struct Node *root,int data)
{
    if(root == NULL)
    {
        root = initializer(data);
    }
    else if(root->data > data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
    }
    return root;
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

struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}

struct Node* delete(struct Node* root, int val)
{
    struct Node* inPre, *inPost;
    // Base cases
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == val)
    {
        free(root);
        return NULL;
    }
    
    // Traversals
    if (root->data > val)
    {
        root->left = delete(root->left,val);
    }
    else if (root->data < val)
    {
        root->right = delete(root->right,val);
    }
    // Found the node
    else
    {   
        if (root->left == NULL)
        {
            inPost = inorderSuccessor(root->right);
            root->data = inPost->data;
            root->right = delete(root->right, inPost->data);
        }
        else if(root->right == NULL)
        {
            inPre = inorderPredecessor(root->left);
            root->data = inPre->data;
            root->left = delete(root->left,inPre->data);
        }
        else
        {
            int lDepth = height(root->left);
            int rDepth = height(root->right);
            if (lDepth<=rDepth)
            {
                inPre = inorderPredecessor(root->left);
                root->data = inPre->data;
                root->left = delete(root->left,inPre->data);
            }
            else
            {
                inPost = inorderSuccessor(root->right);
                root->data = inPost->data;
                root->right = delete(root->right, inPost->data);
            }
        }
    }
    return root;
}

int main(int argc, char *argv[])
{
    int ch,n,data;
    int val[100];
    struct Node *root = NULL;
    printf("Welcome to simple Binary Search Tree!!\n");
    printf("0 to exit.\n1 for insert.\n2 for delete.\n3 for search.\n4 for Pre-Order traversal.\n5 for In-Order traversal.\n6 for Post-Oreder traversal.\n7 for Height.\n");
    
    while(1)
    {
        printf("\n\nEnter Operation to perform : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter no. of elements to insert : ");
            scanf("%d",&n);
            set(val,n);
            root = build(root,val,n);
            break;

        case 2:
            printf("Enter no. to delete : ");
            scanf("%d",&data);
            root = delete(root,data);
            printf("%d deleted successfully!!\n",data);
            break;

        case 3:
            printf("Enter no. to search : ");
            scanf("%d",&data);
            struct Node *temp = search(root,data);
            printf("Data in searched : %d\n",temp->data);
            free(temp);
            break;

        case 0:
            printf("Exited Sucessfully!!\n");
            return 0;

        case 4:
            printf("The Pre-Order : ");
            preorder(root);
            printf("\n");
            break;
        
        case 5:
            printf("The In-Order : ");
            inorder(root);
            printf("\n");
            break;

        case 6:
            printf("The Post-Order : ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("The height of tree is : %d\n",height(root));
            break;

        default:
            printf("Error try again!!\n");
            break;
        }
    }
}