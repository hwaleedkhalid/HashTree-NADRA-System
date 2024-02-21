#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

const int ARRAY_SIZE = 1357;
int primeCol = 0;
int evenCol = 0;
int oddCol = 0;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
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

void insertIntoBST(Node*& root, int num)
{
    if (!root)
    {
        root = new Node(num);
        return;
    }

    if (num < root->data)
        insertIntoBST(root->left, num);
    else if (num > root->data)
        insertIntoBST(root->right, num);
}

void fillData(Node* prime[], Node* even[], Node* odd[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
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
        insertIntoBST(prime[index], num);
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
        insertIntoBST(even[index], num);
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
        insertIntoBST(odd[index], num);
        count++;
    }
}
int searchOdd(Node* odd[], const int size)
{
    if (!odd || size <= 0)
        return 0;

    int num;
    do
    {
        num = rand();
    } while (!isOdd(num));

    int index = Hash(num, size);

    Node* root = odd[index];
    if (!root)
        return 0;

    if (num != root->data)
    {
        oddCol++;
    }

    int count = 0;

    while (root)
    {
        count++;
        if (num == root->data)
        {
            return count;
        }

        if (num < root->data)
            root = root->left;
        else
            root = root->right;
    }

    // Number not found
    oddCol--;
    return 0;
}

int searchEven(Node* even[], const int size)
{
    if (!even || size <= 0)
        return 0;

    int num;
    do
    {
        num = rand();
    } while (!isEven(num));

    int index = Hash(num, size);

    Node* root = even[index];
    if (!root)
        return 0;

    if (num != root->data)
    {
        evenCol++;
    }

    int count = 0;

    while (root)
    {
        count++;
        if (num == root->data)
        {
            return count;
        }

        if (num < root->data)
            root = root->left;
        else
            root = root->right;
    }

    // Number not found
    evenCol--;
    return 0;
}

int searchPrime(Node* prime[], const int size)
{
    if (!prime || size <= 0)
        return 0;

    int num;
    do
    {
        num = rand();
    } while (!isPrime(num));

    int index = Hash(num, size);

    Node* root = prime[index];
    if (!root)
        return 0;

    if (num != root->data)
    {
        primeCol++;
    }

    int count = 0;

    while (root)
    {
        count++;
        if (num == root->data)
        {
            return count;
        }

        if (num < root->data)
            root = root->left;
        else
            root = root->right;
    }

    // Number not found
    primeCol--;
    return 0;
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
        s1 = searchPrime(prime, ARRAY_SIZE);
        s2 = searchEven(even, ARRAY_SIZE);
        s3 = searchOdd(odd, ARRAY_SIZE);

        totalPrimeSearches += s1;
        totalEvenSearches += s2;
        totalOddSearches += s3;
    }

    averagePrime = static_cast<double>(totalPrimeSearches) / 100.0;
    averageEven = static_cast<double>(totalEvenSearches) / 100.0;
    averageOdd = static_cast<double>(totalOddSearches) / 100.0;

    cout << endl << "------------------------------" << endl;
    cout << "Total collisions for Prime: " << primeCol << endl;
    cout << "Total searches for 100 iterations: " << totalPrimeSearches << endl;
    cout << "Average searches for Prime numbers: " << averagePrime << endl;

    
    cout << endl << "------------------------------" << endl;
    cout << "Total collisions for Even: " << evenCol << endl;
    cout << "Total searches for 100 iterations: " << totalEvenSearches << endl;
    cout << "Average searches for Even numbers: " << averageEven << endl;

    
    cout << endl << "------------------------------" << endl;
    cout << "Total collisions for Odd: " << oddCol << endl;
    cout << "Total searches for 100 iterations: " << totalOddSearches << endl;
    cout << "Average searches for Odd numbers: " << averageOdd << endl;

    return 0;
}
