/*****************************************************************
***                                                            ***
***                 linearprobing.cpp                          ***
***                                                            ***
***       This file contains the definations of all            ***
***       functionalities defined in linearprobing.h           ***
***       related to the solution and necessary for            ***
***       the completion of project.                           ***
***                                                            ***
***                                                            ***
***   Author: Waleed Khalid                                    ***
***   Date  : 31st December, 2023                              ***
***                                                            ***
***   Copyright (C) 2023 by Waleed Khalid on behalf of         ***
***   Bahria University Lahore Campus. All rights reserved.    ***
***                                                            ***
******************************************************************/












#include "linearprobing.h"
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

int collisions = 0;
int scount = 0;

void randomData(int arr[])
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned int>(seed));

    arr[0] = rand() % 90000 + 10000;      // 5-digit random number
    arr[1] = rand() % 9000000 + 1000000;  // 7-digit random number
    arr[2] = rand() % 9;                 // Single-digit random number
}
void LinearRandomSearch(LinearProbing table[], const int size)
{
    int id[3];
    for (int i=0; i<100; i++)
    {
        randomData(id);
        Searching(table, size, id);
    }

    cout << "Total Random data found: " << scount << endl << endl;
}


void insertion(LinearProbing table[], const int size)
{
    LinearProbing obj;
    randomData(obj.ID_No);

    int i, j, k, result;
    i = HASH(obj.ID_No[0], size);
    j = HASH(obj.ID_No[1], size);
    k = HASH(obj.ID_No[2], size);
    result = i * 100 + j * 10 + k;
    result = HASH(result, size);

    int s = result;

    if(table[result].ID_No[0] != 0)
    {
        collisions++;
    }

    while (table[result].ID_No[0] != 0 && s < size)
    {
        result = (result + 1) % size;  // move to the next slot
        s ++;
    }

   
    table[result] = obj;
    
}

int HASH(const int number, const int size)
{
    return (number ) % size;
}

void Display(const LinearProbing table[], const int size)
{
    for (int i=0; i<size; i++)
    {
        if ( table[i].ID_No[0] != 0 )
        {
            cout << "ID NO: ";
            for (int j=0; j<3; j++)
            {
                cout << table[i].ID_No[j] << " ";
            }
            cout << endl;
        }
    }
}
void display_col()
{
    cout << "-------Total collusion in Linear Probing are: " << collisions << "--------" << endl;
}

void Searching(LinearProbing table[], const int size, int id[])
{

    int i, j, k, result;
    i = HASH(id[0], size);
    j = HASH(id[1], size);
    k = HASH(id[2], size);
    result = i * 100 + j * 10 + k;
    result = HASH(result, size);

    int s = result;
    while (table[result].ID_No[0] != 0 && s < size && (table[result].ID_No[0] != id[0] || table[result].ID_No[1] != id[1]))
    {
        result = (result + 1) % size; 
        s ++;
    }

    if (s < size && table[result].ID_No[0] == id[0] && table[result].ID_No[1] == id[1] && table[result].ID_No[2] == id[2])
    {
        cout << "ID found at index " << result << endl;
    }
    else
    {
        cout << "ID not found." << endl;
    }
}



void Deletion(LinearProbing table[], const int size)
{
    int id[3];
    cout << "Enter ID No to Delete: ";
    cin >> id[0] >> id[1] >> id[2];

    int i, j, k, result;
    i = HASH(id[0], size);
    j = HASH(id[1], size);
    k = HASH(id[2], size);
    result = i * 100 + j * 10 + k;
    result = HASH(result, size);

    int s = result;
    while (table[result].ID_No[0] != 0 && s < size && (table[result].ID_No[0] != id[0] || table[result].ID_No[1] != id[1]))
    {
        result = (result + 1) % size; 
        s ++;
    }

    if (s < size && table[result].ID_No[0] == id[0] && table[result].ID_No[1] == id[1] && table[result].ID_No[2] == id[2])
    {
        for (int i = 0; i < 3; i++)
        {
            table[result].ID_No[i] = 0;
        }

        
        cout << "Records with ID_No ";
        for (int i=0; i<3; i++) 
        {
            cout << id[i];
        } 
        cout << " deleted Successful. " << endl;
    }
    else
    {
        cout << "Records with this ID_No not found." << endl;
    }
}