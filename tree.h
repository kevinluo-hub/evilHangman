#ifndef TREE_H
#define TREE_H

#include "generic_vector.h"

typedef void* TREE;

TREE tree_init_default(void);
TREE tree_insert(TREE hRoot, MY_STRING key, MY_STRING value);
void increase_size(TREE hRoot, MY_STRING target);
int balanceFactor(TREE hRoot);
TREE AVL_balance(TREE hRoot);
TREE leftRotation(TREE hRoot);
TREE rightRotation(TREE hRoot);

void swap_vector(TREE hRoot, int* pSize,MY_STRING* hLargest, GENERIC_VECTOR* newVector);
void find_biggest_size(TREE hRoot, int* size, MY_STRING* hLargest);
void print_in_order(TREE hRoot);
MY_STRING get_key(TREE hRoot);

void tree_destroy(TREE* phRoot);

#endif
