/*

  C Program to Implement Binary Tree using Linked List

  */

 #include <stdio.h>

 #include <malloc.h>

  

 struct node {

     struct node * left;

     char data;

     struct node * right;

 };

  

 struct node *constructTree( int );

 void inorder(struct node *);

  

 char array[ ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', '', '', 'H' };

 int leftcount[ ] = {  1,   3,   5,   -1,   9,  -1,  -1,   -1,   -1,  -1 };

 int rightcount[ ] = {  2,   4,   6,   -1,  -1,  -1,  -1,   -1,   -1,  -1 };

  

 void main() {

     struct node *root;

     root = constructTree( 0 );

     printf("In-order Traversal: ");

     inorder(root);

 }

  

 struct node * constructTree( int index ) {

     struct node *temp = NULL;

     if (index != -1) {

         temp = (struct node *)malloc( sizeof ( struct node ) );

         temp->left = constructTree( leftcount[index] );

         temp->data = array[index];

         temp->right = constructTree( rightcount[index] );

     }

     return temp;

 }

  

 void inorder( struct node *root ) {

     if (root != NULL) {

         inorder(root->left);

         printf("%c	", root->data);         inorder(root->right);

     }

 }

 /*

Output: 

 In-order Traversal:

 D    B    H    E    A    F    C    G

*/
