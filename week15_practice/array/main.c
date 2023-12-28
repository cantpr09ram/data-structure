#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insert(int tree[], int x, int *size) {
    if (*size >= MAX_SIZE) {
        printf("Tree is full, cannot insert %d\n", x);
        return;
    }

    tree[*size] = x;
    (*size)++;
}

void inorder(int tree[], int size, int root) {
    if (root < size) {
        inorder(tree, size, 2 * root + 1); // Left child
        printf("%d ", tree[root]);
        inorder(tree, size, 2 * root + 2); // Right child
    }
}

int itemInOrder(int tree[], int size, int root, int item) {
    if (root < size) {
        int leftResult = itemInOrder(tree, size, 2 * root + 1, item); // Left child
        if (leftResult != -1) {
            return leftResult;
        }

        if (tree[root] == item) {
            printf("%d ", item);
            return root; // Return the position of the item in inorder traversal
        }

        int rightResult = itemInOrder(tree, size, 2 * root + 2, item); // Right child
        if (rightResult != -1) {
            return rightResult;
        }
    }

    return -1; // Item not found
}

void preorder(int tree[], int size, int root) {
    if (root < size) {
        printf("%d ", tree[root]);
        preorder(tree, size, 2 * root + 1); // Left child
        preorder(tree, size, 2 * root + 2); // Right child
    }
}

void postorder(int tree[], int size, int root) {
    if (root < size) {
        postorder(tree, size, 2 * root + 1); // Left child
        postorder(tree, size, 2 * root + 2); // Right child
        printf("%d ", tree[root]);
    }
}

void levelorder(int tree[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", tree[i]);
    }
}

int main() {
    int tree[MAX_SIZE];
    int size = 0;

    for (int i = 1; i <= 10; i++) {
        insert(tree, i, &size);
    }

    printf("Inorder: ");
    inorder(tree, size, 0);
    printf("\n");

    printf("Preorder: ");
    preorder(tree, size, 0);
    printf("\n");

    printf("Postorder: ");
    postorder(tree, size, 0);
    printf("\n");

    printf("Levelorder: ");
    levelorder(tree, size);
    printf("\n");

    printf("Item Inorder: ");
    iteminorder(tree, size, 0);
    printf("\n");

    return 0;
}
