/*****************************************************************
***                                                            ***
***                 linkedlist.h                               ***
***                                                            ***
***   A header file for the implementation of a simple         ***
***   hash table using open chaining.                          ***
***                                                            ***
***                                                            ***
***   Author: Waleed Khalid                                    ***
***   Date  : 31st December, 2023                              ***
***                                                            ***
***   Copyright (C) 2023 by Waleed Khalid on behalf of         ***
***   Bahria University Lahore Campus. All rights reserved.    ***
***                                                            ***
******************************************************************/



#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LinkedList 
{
    int ID_NO[3];
    LinkedList* next = nullptr;
};

void randomData(int arr[]);
void LinkedListInsertion(LinkedList List[], const int D_Size);
int HASH(const int number, const int D_Size);
void LinkedListSearching(LinkedList array[], const int D_Size, int id[]);
void RandomData(int arr[]);
int Hash(const int number, const int D_Size);
void LinkedListDeletion(LinkedList array[], const int size);
void DisplayLinkedList(LinkedList array[], const int D_Size);
void randomSearch(LinkedList array[], const int D_Size);
void _display_col();
void randomSearch(LinkedList array[], const int D_Size);

#endif
