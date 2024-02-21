/*****************************************************************
***                                                            ***
***                    linkedlist.cpp                          ***
***                                                            ***
***       This file contains the definations of all            ***
***       functionalities defined in linkedlist.h              ***
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











#include "linkedlist.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
int count = 0;

int randS = 0;

void LinkedListInsertion(LinkedList array[], const int D_Size)
{
   int id[3];
   RandomData(id);

   int i, j, k, result;
   i = Hash(id[0], D_Size);
   j = Hash(id[1], D_Size);
   k = Hash(id[2], D_Size);
   result = i * 100 + j * 10 + k;
   result = Hash(result, D_Size);

   if (result >= D_Size || result < 0)
   {
      cout << ("Invalid index returned by Hash function");
   }

   LinkedList* newNode = new LinkedList; 
   newNode->ID_NO[0] = id[0];
   newNode->ID_NO[1] = id[1];
   newNode->ID_NO[2] = id[2];
   newNode->next = nullptr;

   if (array[result].next == nullptr)
   {
       array[result].next = newNode;
   }
   else
   {
        count++;
        LinkedList* current = array[result].next;
        while (current != nullptr)
        {
           

            if (current->next == nullptr)
            {
                current->next = newNode;
                break;
            }

            current = current->next;
        }
    }
}


void randomSearch(LinkedList array[], const int D_Size)
{
    int id[3];
    for (int i=0; i< 100; i++)
    {
        randomData(id);
        LinkedListSearching(array, D_Size, id);
    }
    cout << "Total match values in random Search: " << randS << endl;
}



void RandomData(int arr[])
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned int>(seed));

    arr[0] = rand() % 90000 + 10000;      // 5-digit random number
    arr[1] = rand() % 9000000 + 1000000;  // 7-digit random number
    arr[2] = rand() % 9;                 // Single-digit random number
}

int Hash(const int number, const int D_Size)
{
   int hashValue = (number << 22)  % D_Size;
   if (hashValue < 0)
   {
       hashValue += D_Size;
   }
   return hashValue;
}


void LinkedListSearching(LinkedList array[], const int D_Size, int id[])
{
    int i, j, k, result;
    i = Hash(id[0], D_Size);
    j = Hash(id[1], D_Size);
    k = Hash(id[2], D_Size);
    result = i * 100 + j * 10 + k;
    result = Hash(result, D_Size);

    if (array[result].next == nullptr)
    {
        cout << "No record found with the provided ID." << endl;
        return;
    }

    LinkedList* current = array[result].next;
    while (current != nullptr)
    {
        if (current->ID_NO[0] == id[0] &&
            current->ID_NO[1] == id[1] &&
            current->ID_NO[2] == id[2])
        {
            randS ++;
            cout << "Value found in Database." << endl;
            return;
        }

        current = current->next;
    }

    cout << "No record found with the provided ID." << endl;
}


void LinkedListDeletion(LinkedList array[], const int D_Size)
{
    int id[3];
    cout << "Enter ID No to delete: ";
    cin >> id[0] >> id[1] >> id[2];

    int i, j, k, result;
    i = Hash(id[0], D_Size);
    j = Hash(id[1], D_Size);
    k = Hash(id[2], D_Size);
    result = i * 100 + j * 10 + k;
    result = Hash(result, D_Size);

    if (array[result].next == nullptr)
    {
        cout << "No record found with the provided ID." << endl;
        return;
    }

    LinkedList* current = array[result].next;
    LinkedList* prev = nullptr;

    while (current != nullptr)
    {
        if (current->ID_NO[0] == id[0] &&
            current->ID_NO[1] == id[1] &&
            current->ID_NO[2] == id[2])
        {
            cout << "Value Deleted Successfully." << endl;

            if (prev == nullptr)
            {
                array[result].next = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "No record found with the provided ID." << endl;
}



void DisplayLinkedList(LinkedList array[], const int D_Size)
{
   for (int i = 0; i < D_Size; i++)
   {
       if (array[i].next != nullptr)
       {
           cout << "ID NO: ";
           for (int j = 0; j < 3; j++)
           {
               cout << array[i].next->ID_NO[j] << " ";
           }
           cout << endl;
       }
   }
}


void _display_col()
{
    cout << "------Total collusion in Linked List Based are: " << count << "--------" << endl;
    cout << "Counter reset to 0" << endl;
    count = 0;
}