/*****************************************************************
***                                                            ***
***                     bstbased.cpp                           ***
***                                                            ***
***       This file contains the definations of all            ***
***       functions related to Binary Search Tree(BST)         ***
***       based implementation of project of DSA. The          ***
***       prototypes of all these are defined bstbased.h       ***
***                                                            ***
***                                                            ***
***                                                            ***
***   Author: Waleed Khalid                                    ***
***   Date  : 31st December, 2023                              ***
***                                                            ***
***   Copyright (C) 2023 by Waleed Khalid on behalf of         ***
***   Bahria University Lahore Campus. All rights reserved.    ***
***                                                            ***
******************************************************************/







#include "bstbased.h"
#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

int trash = 0;   // to count collisions 
int temp = 0; // for 100 random search collision count

int _HASH(const int number, const int D_Size)
{
  const int A = 31;  // a prime number
    const int B = 17;  // another prime number

    // Modified hash function
    return ((A * number + B) % D_Size + D_Size) % D_Size;


}



void _RandomData(int arr[])
{
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned int>(seed));

    arr[0] = rand() % 90000 + 10000;      // 5-digit random number
    arr[1] = rand() % 9000000 + 1000000;  // 7-digit random number
    arr[2] = rand() % 9;                 // Single-digit random number
}


void BSTInsertion(BST array[], const int SIZE)
{
    int id[3];
    _RandomData(id);

    int i, j, k, result;
    i = _HASH(id[0], SIZE);
    j = _HASH(id[1], SIZE);
    k = _HASH(id[2], SIZE);
    result = i * 100 + j * 10 + k;
    result = _HASH(result, SIZE);

    if (result >= SIZE || result < 0)
    {
        cout << "Invalid index returned by Hash function" << endl;
        return;
    }

    BST* newNode = new BST;
    newNode->ID_[0] = id[0];
    newNode->ID_[1] = id[1];
    newNode->ID_[2] = id[2];
    newNode->left = nullptr;
    newNode->right = nullptr;




    insertNode(&array[result], newNode);
}

void insertNode(BST *root, BST *node) 
{
    if (!root || !node) 
    {
        cout << "Invalid input in insertNode" << endl;
        return;
    }

    int location = findLocation(root->ID_, node->ID_);

    while (location != 0)
    {
        if (location > 0 && !root->right) 
        {
            root->right = node;
            break;
        }
        else if (location < 0 && !root->left) 
        {
            root->left = node;
            break;
        }
        else
        {
            trash++;
            root = (location > 0) ? root->right : root->left;
        }

        location = findLocation(root->ID_, node->ID_);
    }

    if (location == 0)
    {
        cout << "Duplicate ID Number found" << endl;
    }
}




int findLocation(const int *root, const int *node) 
{
    if (!root || !node) 
    {
        cout << "Invalid input in findLocation" << endl;
        return 0; 
    }

    for (int i = 0; i < 3; i++)
    {
        if (root[i] > node[i])
        {
            return -1;
        }
        else if (root[i] < node[i])
        {
            return 1;
        }
    }
    return 0;
}





void BSTDeletion(BST tree[], const int size)
{
    int id[3];
    cout << "Enter ID No to Delete: ";
    cin >> id[0] >> id[1] >> id[2];

    int i, j, k, result;
    i = _HASH(id[0], size);
    j = _HASH(id[1], size);
    k = _HASH(id[2], size);
    result = i * 100 + j * 10 + k;
    result = _HASH(result, size);

    BST* temp = &tree[result];
    
    deleteNode(temp, id);

}

void deleteNode(BST *&root, const int ID[])      // Function to delete a specific node 
{
    if (!root)
    {
        cout << "BST is empty." << endl;
        return;
    }

    BST *parent = nullptr;
    BST *current = root;

    // Search for the node to delete and its parent
    while (current)
    {
        int location = findLocation(current->ID_, ID);

        if (location > 0)
        {
            parent = current;
            current = current->right;
        }
        else if (location < 0)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            if (!current->left && !current->right)           // Case 1: Node with no children
            {
                if (parent)
                {
                    if (parent->left == current)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                else
                {
                    delete current;
                    root = nullptr;
                }
            }
            
            else if (current->left && current->right)          // Case 2: Node with two children
            {
                BST *del = findMin(current->right);

                for (int i=0; i<3; i++)
                {
                    current->ID_[i] = del->ID_[i];
                }

                deleteNode(current->right, del->ID_);
            }
            
            else          // Case 3: Node with one child
            {
                BST *child = (current->left) ? current->left : current->right;

                if (parent)
                {
                    if (parent->left == current)
                        parent->left = child;
                    else
                        parent->right = child;
                }
                else
                {
                    root = child;
                }

                delete current;
            }

            cout << "Node with ID number ";
            for(int i=0; i<3; i++)
            {
                cout << ID[i] << " ";
            }
            cout << " Deleted successfully." << endl;
            return;
        }
    }

    cout << "Node with ID number ";
            for(int i=0; i<3; i++)
            {
                cout << ID[i] << " ";
            } 
    cout << " not found." << endl;
}

BST *findMin(BST *ptr)  // Function to the smallest element in a tree or subtree (used in deleteNode function)
{
    while (ptr->left)
    {
        ptr = ptr->left;
    }

    return ptr;
}

void randSearch(BST *root, const int SIZE)
{
    int id[3];
    for (int i=0; i<100; i++)
    {
        _RandomData(id);
        BSTSearch(root, SIZE, id);
    }

    cout << "Total random data matches: " << temp << endl;
    
}
void BSTSearch(BST *root, const int SIZE, int id[])
{

    int i, j, k, result;
    i = _HASH(id[0], SIZE);
    j = _HASH(id[1], SIZE);
    k = _HASH(id[2], SIZE);
    result = i * 100 + j * 10 + k;
    result = _HASH(result, SIZE);

    BST *temp = &root[result];  

    search(temp, id);
}

void search(BST *root, const int id[])  
{
    if (!root || !id)
    {
        cout << "!!! Tree is Empty or Invalid Address." << endl;
        return;
    }

    BST *temp = root;

    while (temp)
    {
        int location = findLocation(temp->ID_, id);

        if (location > 0)
        {
            temp = temp->right;
        }
        else if (location < 0)
        {
            temp = temp->left;
        }
        else
        {
            if ((temp->ID_[0] == id[0]) && (temp->ID_[1] == id[1]) && (temp->ID_[2] == id[2]))
            {
                temp ++;
                cout << "ID number found in database." << endl;
            }
            else
            {
                cout << "Records with this ID not found." << endl;
            }
            return;
        }
    }

    cout << "!!! Record Not found with this ID." << endl;
}

void BSTDisplay(BST tree[], const int SIZE)
{
    for (int i=0; i<SIZE; i++)
    {
        if (tree[i].left != nullptr || tree[i].right != nullptr)
        {
            inOrder(&tree[i]);
        }
        
    }

    
}


void inOrder(BST *root)
{
    if(root)
    {
        inOrder(root->left);

        if(root->ID_[0] != 0 )
        {
            cout << "ID NO: ";
            for (int i=0; i<3; i++)
            {
                cout << root->ID_[i] << " ";
            }
            cout << endl;
        }
        inOrder(root->right);
    }
    return;
}

void DisplayCollisions()
{
    cout << "Total number of collisions are: " << trash << endl;
}