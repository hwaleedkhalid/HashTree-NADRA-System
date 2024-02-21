/*****************************************************************
***                                                            ***
***                   bstbased.h                               ***
***                                                            ***
***   A header file for the implementation of a simple         ***
***   hash table using open chaining BST Based.                ***
***                                                            ***
***                                                            ***
***   Author: Waleed Khalid                                    ***
***   Date  : 31st December, 2023                              ***
***                                                            ***
***   Copyright (C) 2023 by Waleed Khalid on behalf of         ***
***   Bahria University Lahore Campus. All rights reserved.    ***
***                                                            ***
******************************************************************/







#ifndef BSTBASED_H
#define BSTBASED_H


struct BST 
{
    int ID_[3];
    BST *left = nullptr;
    BST *right = nullptr;
};


int _HASH(const int number, const int D_Size);
void _RandomData(int arr[]);
void BSTInsertion(BST array[], const int SIZE);
int findLocation(const int *root, const int *node) ;
void insertNode(BST *root, BST *node) ;
BST *findMin(BST *ptr);
void deleteNode(BST *&root, const int ID[]) ;
void BSTDeletion(BST tree[], const int size);
void search(BST *root, const int id[]) ;
void BSTSearch(BST *root, const int SIZE, int id[]);
void BSTDisplay(BST tree[], const int SIZE);
void inOrder(BST *root);
void DisplayCollisions();
void randSearch(BST *root, const int SIZE);


#endif
