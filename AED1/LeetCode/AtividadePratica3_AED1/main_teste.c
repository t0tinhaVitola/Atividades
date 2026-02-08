/*CÓDIGO FEITO APENAS PARA RODAR O VALGRIND, VISTO QUE A SOLUÇÃO APRESENTADA NO LEETCODE UTILIZA ALOCAÇÃO DINÃMICA. 
A FUNÇÃO "insertIntoBST" QUE É A SOLUÇÃO DO PROBLEMA DO LEETCODE FOI FEITA INTEIRAMENTE EM AULA E APENAS NA PLATAFORMA DO LEETCODE.
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if ( root == NULL ) {
        root = malloc(sizeof( struct TreeNode ));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    
    if ( val < root->val ) {
        root->left = insertIntoBST( root->left, val );
    } else {
        root->right = insertIntoBST( root->right, val );
    }
    
    return root;
}

void freeTree( struct TreeNode** root ) {
    if ( *root == NULL || root == NULL )
        return;

    freeTree(&(*root)->left);
    freeTree(&(*root)->right);

    free(*root);
    *root = NULL;

    return;
}

void printTree( struct TreeNode* root ) {
    if ( root == NULL)
        return;
    printf("[ %d ] -> ", root->val);
    printTree(root->left);
    printTree(root->right);

    return;
}

int main () {

    struct TreeNode* root = NULL;
    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    insertIntoBST(root, 5);
    printTree(root);
    freeTree(&root);
    return 0;
}
