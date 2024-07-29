#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
typedef struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}tree;

// Function to create a new node
tree* newNode(int data) 
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
tree* insert(tree* root, int data) 
{
    if (root == NULL) 
    {
        return newNode(data);
    } 
    else 
    {
        if (data <= root->data) 
        {
            root->left = insert(root->left, data);
        } 
        else 
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to find the height of the BST
int findHeight(tree* root) 
{
    if (root == NULL) 
    {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to count the number of nodes in the BST
int countNodes(tree* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaf nodes in the BST
int countLeafNodes(tree* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    tree* root = NULL;
    int choice;

    do {
        printf("1. Insert\n");
        printf("2. Find Height\n");
        printf("3. Count Nodes\n");
        printf("4. Count Leaf Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            }
            case 2: {
                printf("Height of the BST: %d\n", findHeight(root));
                break;
            }
            case 3: {
                printf("Total number of nodes in the BST: %d\n", countNodes(root));
                break;
            }
            case 4: {
                printf("Total number of leaf nodes in the BST: %d\n", countLeafNodes(root));
                break;
            }
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
