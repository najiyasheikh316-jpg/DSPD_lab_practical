#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* createTree() {
    int value;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node* newNode = createNode(value);

    printf("Enter left child of %d:\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = createTree();

    return newNode;
}

// Traversal 
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    return (search(root->left, key) || search(root->right, key));
}


int main() {
    struct Node* root = NULL;
    int key;

    printf("Create the Binary Tree:\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Found\n");
    else
        printf("NULL\n");

    return 0;
}
// Create the Binary Tree:
// Enter data (-1 for no node): 10
// Enter left child of 10:
// Enter data (-1 for no node): 5
// Enter left child of 5:
// Enter data (-1 for no node): -1
// Enter right child of 5:
// Enter data (-1 for no node): 7
// Enter left child of 7:
// Enter data (-1 for no node): -1
// Enter right child of 7:
// Enter data (-1 for no node): -1
// Enter right child of 10:
// Enter data (-1 for no node): 15
// Enter left child of 15:
// Enter data (-1 for no node): -1
// Enter right child of 15:
// Enter data (-1 for no node): 20
// Enter left child of 20:
// Enter data (-1 for no node): -1
// Enter right child of 20:
// Enter data (-1 for no node): -1

// Inorder Traversal: 5 7 10 15 20 
// Preorder Traversal: 10 5 7 15 20 
// Postorder Traversal: 7 5 20 15 10 

// Enter element to search: 7
// Found

