/*****************************************************************
***                                                            ***
***              linearprobing.h                               ***
***                                                            ***
***   A header file for the implementation of a simple         ***
***   hash table using linear probing.                         ***
***                                                            ***
***                                                            ***
***   Author: Waleed Khalid                                    ***
***   Date  : 31st December, 2023                              ***
***                                                            ***
***   Copyright (C) 2023 by Waleed Khalid on behalf of         ***
***   Bahria University Lahore Campus. All rights reserved.    ***
***                                                            ***
******************************************************************/






#ifndef LINEARPROBING_H
#define LINEARPROBING_H


struct LinearProbing 
{
    int ID_No[3];
};
void randomData(int arr[]);
void insertion(LinearProbing table[], const int size);
int HASH(const int number, const int size);
void Searching(LinearProbing table[], const int size, int id[]);
void Deletion(LinearProbing table[], const int size);
void Display(const LinearProbing table[], const int size);
void display_col();
void LinearRandomSearch(LinearProbing table[], const int size);


#endif
