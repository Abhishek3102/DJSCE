#include <stdio.h>
#include <stdlib.h>
struct node {
int value;
struct node* left;
struct node* right;
};
struct node* root;
struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);
int count(struct node* r);
int height(struct node* r);
int main() {
int choice, data;
root = NULL;
do {
printf("\n*** Binary Tree Traversal***");
printf("\n1. Enter Node in Tree");
printf("\n2. InOrder Traversal");
printf("\n3. PreOrder Traversal");
printf("\n4. PostOrder Traversal");
printf("\n5. Number of Nodes in the Tree");
printf("\n6. Height of the Tree");
printf("\n7. End Program");
printf("\n Enter Your Choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter Data: ");
scanf("%d", &data);
root = insert(root, data);
break;
case 2:
printf("Inorder Traversal: ");
inOrder(root);
printf("\n");
break;
case 3:
printf("Preorder Traversal: ");
preOrder(root);
printf("\n");

break;
case 4:
printf("Postorder Traversal: ");
postOrder(root);
printf("\n");
break;
case 5:
printf("Number of Nodes in Tree: %d", count(root));
break;
case 6:
printf("Height of the Tree: %d", height(root));
break;
case 7:
printf("\nEnd Program\n");
break;
default:
printf("\nPlease Enter a Choice from 1 to 7\n");
}
} while (choice != 7);
return 0;
}
struct node* insert(struct node* r, int data) {
if (r == NULL) {
r = (struct node*)malloc(sizeof(struct node));
r->value = data;
r->left = NULL;
r->right = NULL;
} else if (data < r->value) {
r->left = insert(r->left, data);
} else {
r->right = insert(r->right, data);
}
return r;
}
void inOrder(struct node* r) {
if (r != NULL) {
inOrder(r->left);
printf("%d ", r->value);
inOrder(r->right);
}
}
void preOrder(struct node* r) {
if (r != NULL) {
printf("%d ", r->value);
preOrder(r->left);
preOrder(r->right);
}
}
void postOrder(struct node* r) {

if (r != NULL) {
postOrder(r->left);
postOrder(r->right);
printf("%d ", r->value);
}
}
int count(struct node* r) {
if (r == NULL) return 0;
return (1 + count(r->left) + count(r->right));
}
int height(struct node* r) {
int hgt_left, hgt_right;
if (r == NULL) return 0;
hgt_left = height(r->left);
hgt_right = height(r->right);
return (1 + (hgt_left > hgt_right ? hgt_left : hgt_right));
}