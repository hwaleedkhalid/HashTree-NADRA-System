#include <iostream>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 1357;
int primeCol = 0;
int evenCol = 0;
int oddCol = 0;

struct Node
{
    int data;
    Node* next;
};


bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool isEven(int n)
{
    return (n % 2 == 0);
}

bool isOdd(int n)
{
    return (n % 2 == 1);
}

int Hash(const int num, const int size)
{
    return num % size;
}

void insertIntoList(Node*& head, int num)
{
    Node* newNode = new Node{num, nullptr};
    newNode->next = head;
    head = newNode;
}

void fillData(Node* prime[], Node* even[], Node* odd[], const int size)
{
    for (int i = 0; i < size; ++i) {
        prime[i] = nullptr;
        even[i] = nullptr;
        odd[i] = nullptr;
    }

    int count = 0;
    while (count < 1000)
    {
        int num;
        do
        {
            num = rand();

        } while (!isPrime(num));

        int index = Hash(num, size);
        insertIntoList(prime[index], num);
        count++;
    }

    count = 0;
    while (count < 1000)
    {
        int num;
        do
        {
            num = rand();

        } while (!isEven(num));

        int index = Hash(num, size);
        insertIntoList(even[index], num);
        count++;
    }

    count = 0;
    while (count < 1000)
    {
        int num;
        do
        {
            num = rand();

        } while (!isOdd(num));

        int index = Hash(num, size);
        insertIntoList(odd[index], num);
        count++;
    }
}

int searchInList(Node* list[], const int size, int& colCounter)
{
    int num;
    int count = 0;

    do
    {
        num = rand();
    } while (!isPrime(num)); 

    int index = Hash(num, size);
    Node* temp = list[index];

    while (temp != nullptr && temp->data != num)
    {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr)
    {
        colCounter++;
    }

    return count;
}

int main()
{
    Node* prime[ARRAY_SIZE];
    Node* even[ARRAY_SIZE];
    Node* odd[ARRAY_SIZE];

    int totalPrimeSearches = 0;
    int totalEvenSearches = 0;
    int totalOddSearches = 0;

    double averagePrime = 0;
    double averageEven = 0;
    double averageOdd = 0;

    fillData(prime, even, odd, ARRAY_SIZE);

    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    for (int i = 0; i < 100; i++)
    {
        s1 = searchInList(prime, ARRAY_SIZE, primeCol);
        s2 = searchInList(even, ARRAY_SIZE, evenCol);
        s3 = searchInList(odd, ARRAY_SIZE, oddCol);
        totalPrimeSearches += s1;
        totalEvenSearches += s2;
        totalOddSearches += s3;
    }

    averagePrime = static_cast<double> (totalPrimeSearches) / 100.0;
    averageEven = static_cast<double> (totalEvenSearches) / 100.0;
    averageOdd = static_cast<double> (totalOddSearches) / 100.0;

    cout << endl << "------------------------------" << endl;
    cout << "Total searches for 100 iterations (Prime): " << totalPrimeSearches << endl;
    cout << "Total collisions for prime search: " << primeCol << endl;
    cout << "Average searches per iteration (Prime): " << averagePrime << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Total searches for 100 iterations (Even): " << totalEvenSearches << endl;
    cout << "Total collisions for Even search: " << evenCol << endl;
    cout << "Average searches per iteration (Even): " << averageEven << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Total searches for 100 iterations (Odd): " << totalOddSearches << endl;
    cout << "Total collisions for Odd search: " << oddCol << endl;
    cout << "Average searches per iteration (Odd): " << averageOdd << endl;

    return 0;
}
