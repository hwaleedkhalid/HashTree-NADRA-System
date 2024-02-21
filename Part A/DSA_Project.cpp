/*****************************************************************
***                                                            ***
***                DSA_Project (Part-01).cpp                   ***
***                                                            ***
***    This file contains the implementation of Data           ***
***    Structures and Algorithms (DSA) final project           ***
***    Part 01. All necessary related files are                ***
***    included in this directory.                             ***
***                                                            ***
***                                                            ***
***   Author: Waleed Khalid                                    ***
***   E-ID:   03-134222-111                                    ***
***   Section: BS CS-3B                                        ***
***   Contact: waleed.hafizkhalid@gmail.com                    ***
***   Date  : 31st December, 2023                              ***
***   Supervisor: Dr. Umair Ayub                               ***
***                                                            ***
***   Semester: Autumn '23                                     ***
***   Department: Computer Science                             ***
***   University: Bahria University Lahore Campus              ***
***                                                            ***
***                                                            ***
***   Copyright (C) 2023 by Waleed Khalid                      ***
***                                                            ***
***                                                            ***
***   To compile this file and related files use the           ***
***   following command in VS Code Shell or in BASH            ***
***   terminal:                                                ****************************************************************
***                                                                                                                           |
***   g++ DSA_Project.cpp linearprobing/linearprobing.cpp linkedlist/linkedlist.cpp bstbased/bstbased.cpp -o DSA              |
***                                                                                                                           |
***                                                            ***************************************************************`
***   Now run the .exe file BY the following                   ***
***   command in VS Code Terminal or BASH:                     ***
***            ./DSA                                           ***
***                                                            ***
***   Please note that you need to have C++ installed on your  ***
***   machine and also a compiler like GCC/CLANG is required.  ***
***                                                            ***
***   If any issues occur then please contact the author.      ***
***                                                            ***
***                                                            ***
******************************************************************/







#include <iostream>
#include "linearprobing/linearprobing.h"
#include "linkedlist/linkedlist.h"
#include "bstbased/bstbased.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <chrono>
using namespace std;



void Linear_Probing();
void Linked_List();
void BST_Based();


int main()
{
    int main;
    do
    {
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\t\t\t\t" << "|            Main Menu              |" << endl;
        cout << "\t\t\t\t" << "|            `````````              |" << endl;
        cout << "\t\t\t\t" << "|  1-> Linear Probing Technique     |" << endl;
        cout << "\t\t\t\t" << "|  2-> Linked-List based Chaining   |" << endl;
        cout << "\t\t\t\t" << "|  3-> BSD-based Chaining           |" << endl;
        cout << "\t\t\t\t" << "|  0-> Exit                         |" << endl;
        cout << "\t\t\t\t" << "|                                   |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << endl;
        cout << "\t\t\t\t" << "=> Enter Your Choice: " ;
        cin >> main;
        cout << endl;
        switch (main)
        {
            case 1:
            {
                cout << "You selected Linear Probing Technique...." << endl;
                Linear_Probing();
                break;
            }
            case 2:
            {
                cout << "You selected Linked-List-Based Chaining...." << endl;
                Linked_List();
                break;
            }
            case 3:
            {
                cout << "You selected BST-Based Chaining...." << endl;
                BST_Based();
                break;
            }
            case 0:
            {
                system("cls");
                cout << "\n\n\n\n" << endl;
                cout << "\t\t\t\t" << "---------Shutting Down the System--------" << endl;
                Sleep(1500);
                break;
            }
            default:
            {
                cout << "!!! Invalid Input." << endl;
                cout << "Please Try Again." << endl;
                Sleep(1500);
                system("cls");
                break;
            }
        }
    } while (main != 0);
    
    
    return 0;
}

void Linear_Probing()
{
   
    const int size = 1357;
    LinearProbing table[size];

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<3; j++)
        {
            table[i].ID_No[j] = 0;
        }
    }

    for (int i=0; i<1000; i++)
    {
        insertion(table, size);
    }
    int ch;
    do
    {
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\t\t\t\t" << "|          Linear Probing           |" << endl;
        cout << "\t\t\t\t" << "|          ``````````````           |" << endl;
        cout << "\t\t\t\t" << "|  1-> Insertion                    |" << endl;
        cout << "\t\t\t\t" << "|  2-> Deletion                     |" << endl;
        cout << "\t\t\t\t" << "|  3-> Searching                    |" << endl;
        cout << "\t\t\t\t" << "|  4-> Display Data + Collusion     |" << endl;
        cout << "\t\t\t\t" << "|  0-> Bach to Main Menu            |" << endl;
        cout << "\t\t\t\t" << "|                                   |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\n";
        cout << "\t\t\t\t" << "=> Enter Your Choice: " ;
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                insertion(table, size);
                break;
            }
            case 2:
            {
                Deletion(table, size);
                break;
            }
            case 3:
            {
                LinearRandomSearch(table, size);    
                int id[3];
                cout << "Enter ID No to search: ";
                cin >> id[0] >> id[1] >> id[2];
                Searching(table, size, id);
                break;
            }
            case 4:
            {
                Display( table, size);
                display_col();
                break;
            }
            case 0:
            {
                system("cls");
                cout << "\n\n\n\n" ;
                cout << "\t\t\t\t" << "-------Going Back to Main Menu-------" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
            default:
            {
                cout << "!!! Invalid Input." << endl;
                cout << "Please Try Again." << endl;
                Sleep(1500);
                system("cls");
                break;
            }
        }
    } while (ch != 0);
    
}

void Linked_List()
{
    int D_Size = 1357;
    LinkedList array[D_Size];

    for (int i = 0; i < D_Size; ++i)
    {
        array[i].next = nullptr;
    }
    
    for (int i=0; i<1000; i++)
    {
        LinkedListInsertion(array, D_Size);
    }


    int ch;
    do
    {
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\t\t\t\t" << "|         Linked List Based         |" << endl;
        cout << "\t\t\t\t" << "|         `````````````````         |" << endl;
        cout << "\t\t\t\t" << "|  1-> Insertion                    |" << endl;
        cout << "\t\t\t\t" << "|  2-> Deletion                     |" << endl;
        cout << "\t\t\t\t" << "|  3-> Searching                    |" << endl;
        cout << "\t\t\t\t" << "|  4-> Display Data + Collusion     |" << endl;
        cout << "\t\t\t\t" << "|  0-> Bach to Main Menu            |" << endl;
        cout << "\t\t\t\t" << "|                                   |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\n";
        cout << "\t\t\t\t" << "=> Enter Your Choice: " ;
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                LinkedListInsertion(array, D_Size);
                break;
            }
            case 2:
            {
                LinkedListDeletion(array, D_Size);
                break;
            }
            case 3:
            {
                randomSearch(array, D_Size);
                int id[3];
                cout << "Enter ID No to search: ";
                cin >> id[0] >> id[1] >> id[2];
                LinkedListSearching(array, D_Size, id);
                break;
            }
            case 4:
            {
                DisplayLinkedList(array, D_Size);
                _display_col();
                break;
            }
            case 0:
            {
                
                system("cls");
                cout << "\n\n\n\n" ;
                cout << "\t\t\t\t" << "-------Going Back to Main Menu-------" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
            default:
            {
                cout << "!!! Invalid Input." << endl;
                cout << "Please Try Again." << endl;
                Sleep(1500);
                system("cls");
                break;
            }
        }
    } while (ch != 0);
}

void BST_Based()
{
    int SIZE = 1397;
    BST tree[SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        tree[i].left = nullptr;
        tree[i].right = nullptr;
        for(int j=0; j<3; j++)
        {
            tree[i].ID_[j] = 0;
        }
    }
    
    for (int i=0; i<1000; i++)
    {
        BSTInsertion(tree, SIZE);
    }


    int ch;
    do
    {
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\t\t\t\t" << "|             BST Based             |" << endl;
        cout << "\t\t\t\t" << "|             `````````             |" << endl;
        cout << "\t\t\t\t" << "|  1-> Insertion                    |" << endl;
        cout << "\t\t\t\t" << "|  2-> Deletion                     |" << endl;
        cout << "\t\t\t\t" << "|  3-> Searching                    |" << endl;
        cout << "\t\t\t\t" << "|  4-> Display Data + Collusion     |" << endl;
        cout << "\t\t\t\t" << "|  0-> Bach to Main Menu            |" << endl;
        cout << "\t\t\t\t" << "|                                   |" << endl;
        cout << "\t\t\t\t" << "+-----------------------------------+" << endl;
        cout << "\n";
        cout << "\t\t\t\t" << "=> Enter Your Choice: " ;
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                BSTInsertion(tree, SIZE);
                break;
            }
            case 2:
            {
                BSTDeletion(tree, SIZE);
                break;
            }
            case 3:
            {
                randSearch(tree, SIZE);
                int id[3];
                cout << "Enter ID No to search: ";
                cin >> id[0] >> id[1] >> id[2];
                BSTSearch( tree,  SIZE, id);
                break;
            }
            case 4:
            {
                BSTDisplay( tree, SIZE);
                DisplayCollisions();
                break;
            }
            case 0:
            {
                system("cls");
                cout << "\n\n\n\n" ;
                cout << "\t\t\t\t" << "-------Going Back to Main Menu-------" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
            default:
            {
                cout << "!!! Invalid Input." << endl;
                cout << "Please Try Again." << endl;
                Sleep(1500);
                system("cls");
                break;
            }
        }
    } while (ch != 0);
}
