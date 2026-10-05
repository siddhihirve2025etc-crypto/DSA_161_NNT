#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory Allocation failed!\n");
        return NULL;
    }
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorderTraversal(struct node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node* root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal (sorted): ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal:         ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder traversal:        ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}