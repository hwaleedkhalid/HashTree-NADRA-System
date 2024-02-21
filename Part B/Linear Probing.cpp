#include <iostream>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 1357;
int primeCol = 0;
int evenCol = 0;
int oddCol = 0;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
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

void fillData(int prime[], int even[], int odd[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        prime[i] = 0;
        even[i] = 0;
        odd[i] = 0;
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

        while (prime[index] != 0)
        {
            index = (index + 1) % size;
        }

        prime[index] = num;
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

        while (even[index] != 0)
        {
            index = (index + 1) % size;
        }

        even[index] = num;
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

        while (odd[index] != 0)
        {
            index = (index + 1) % size;
        }

        odd[index] = num;
        count++;
    }
}

int primeSearch(const int prime[], const int size)
{
    int num;
    int count = 0;

    do
    {
        num = rand();
    } while (!isPrime(num)); 

    int index = Hash(num, size);

    if (prime[index] != num)
    {
        primeCol++;
    }

    while (prime[index] != num && count < size)
    {
        index = (index + 1) % size;
        count++;
    }

    if (prime[index] != num)
    {
        //Error: Number not found in array.
        primeCol--;
        return count;  
    }


    return count; \
}


int evenSearch(const int even[], const int size)
{
    int num;
    int count = 0;

    do
    {
        num = rand();
    } while (!isEven(num));

    int index = Hash(num, size);

    if (even[index] != num)
    {
        evenCol++;
    }

    while (even[index] != num && count < size)
    {
        index = (index + 1) % size;
        count++;
    }

    if (even[index] != num)
    {
        // Error: Number not found in array.
        evenCol--;
        return count;
    }

    return count;
}

int oddSearch(const int odd[], const int size)
{
    int num;
    int count = 0;

    do
    {
        num = rand();
    } while (!isOdd(num));

    int index = Hash(num, size);

    if (odd[index] != num)
    {
        oddCol++;
    }

    while (odd[index] != num && count < size)
    {
        index = (index + 1) % size;
        count++;
    }

    if (odd[index] != num)
    {
        // Error: Number not found in array.
        oddCol--;
        return count;
    }

    return count;
}




int main()
{
    int prime[ARRAY_SIZE];
    int even[ARRAY_SIZE];
    int odd[ARRAY_SIZE];

    int totalPrimeSearches = 0;
    int totalEvenSearches = 0;
    int totalOddSearches = 0;

    double averagePrime = 0 ;
    double averageEven = 0 ;
    double averageOdd = 0 ;

    fillData(prime, even, odd, ARRAY_SIZE);

    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    for (int i = 0; i < 100; i++)
    {
        s1 = primeSearch(prime , ARRAY_SIZE);
        s2 = evenSearch(even, ARRAY_SIZE);
        s3 = oddSearch(odd, ARRAY_SIZE);
        totalPrimeSearches += s1;
        totalEvenSearches += s2;
        totalOddSearches += s3;
    }

    averagePrime = static_cast<double> (totalPrimeSearches) / 100.0;
    averageEven = static_cast<double> (totalEvenSearches) / 100.0;
    averageOdd = static_cast<double> (totalOddSearches) / 100.0;

    cout << endl << "------------------------------" << endl;
    cout << "Total collisions for prime search: " << primeCol << endl;
    cout << "Total searches for 100 iterations: " << totalPrimeSearches << endl;
    cout << "Average searches per iteration: " << averagePrime << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Total collisions for Even search: " << evenCol << endl;
    cout << "Total searches for 100 iterations: " << totalEvenSearches << endl;
    cout << "Average searches per iteration: " << averageEven << endl;

    cout << endl << "------------------------------" << endl;
    cout << "Total collisions for Odd search: " << oddCol << endl;
    cout << "Total searches for 100 iterations: " << totalOddSearches << endl;
    cout << "Average searches per iteration: " << averageOdd << endl;

    return 0;
}

