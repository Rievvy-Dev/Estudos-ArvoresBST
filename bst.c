//Este arquivo contém todas as implementações das funções do arquivo de biblioteca.

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Tree insertNode (Tree root, int value) {
    if (root == NULL) {
        Tree node = (Tree)malloc(sizeof(root));
        node->value = value;
        node->leftNode = NULL;
        node->rightNode = NULL;
        return node;
    } else {
        if (value > root->value){
            root->rightNode = insertNode(root->rightNode, value);
        } else {
            root->leftNode = insertNode(root->leftNode, value);
        }
        return root;
    }
}

Tree searchNode (Tree root, int value) {
    if (root->value == value) {
        return root;
    } else {
        if (value > root->value) {
            root = searchNode(root->rightNode, value);
        } else {
            root = searchNode(root->leftNode, value);
        }
        return root;
    }
}

int highestValue (Tree root) {
    if (root->rightNode == NULL && root->leftNode == NULL) {
        return root->value;
    } else if (root->rightNode != NULL) {
        int highest = highestValue(root->rightNode);
    } else {
        return root->value;
    }
}

Tree deleteNode (Tree root, int value) {
    if (root->value == value) {
        if (root->rightNode == NULL && root->leftNode == NULL) {
            free(root);
            return NULL;
        } else {
            if (root->rightNode == NULL && root->leftNode != NULL) {
                Tree assistant = root->leftNode;
                free(root);
                return assistant;
            } else if (root->rightNode != NULL && root->leftNode == NULL) {
                Tree assistant = root->rightNode;
                free(root);
                return assistant;
            } else {
                int highest = highestValue(root->leftNode);
                root->value = highest;
                root->leftNode = deleteNode(root->leftNode, highest);
                return root;
            }
        }
    } else {
        if (value > root->value) {
            root->rightNode = deleteNode(root->rightNode, value);
        } else {
            root->leftNode = deleteNode(root->leftNode, value);
        }
        return root;
    }
}

int amountPairs (Tree root) {
    int amount = 0;
    if (root->value%2 == 0) {
        amount++;
        return amount;
    }
}

void preOrder (Tree root) {
    if (root != NULL) {
        printf("[%d]", root->value);
        preOrder(root->leftNode);
        preOrder(root->rightNode);
    }
}

void inOrder (Tree root) {
    if (root != NULL) {
        inOrder(root->leftNode);
        printf("[%d]", root->value);
        inOrder(root->rightNode);
    }
}

void posOrder (Tree root) {
    if (root != NULL) {
        posOrder(root->leftNode);
        posOrder(root->rightNode);
        printf("[%d]", root->value);
    }
}

void descending (Tree root) {
    if (root != NULL) {
        descending(root->rightNode);
        printf("[%d]", root->value);
        descending(root->leftNode);
    }
}
