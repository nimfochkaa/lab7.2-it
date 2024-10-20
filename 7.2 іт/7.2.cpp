#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int SearchMinOfMax(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "Enter number of rows (k): ";
    cin >> k;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int minOfMaxes = SearchMinOfMax(a, k, n);
    cout << "Minimum of the maximum elements in each row = " << minOfMaxes << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SearchMinOfMax(int** a, const int k, const int n)
{
    int minOfMaxes; 

    for (int i = 0; i < k; i++)
    {
        int maxInRow = a[i][0]; 

        for (int j = 1; j < n; j++)
        {
            if (a[i][j] > maxInRow)
                maxInRow = a[i][j];
        }

        if (i == 0)
            minOfMaxes = maxInRow;
        else if (maxInRow < minOfMaxes)
            minOfMaxes = maxInRow;
    }

    return minOfMaxes;
}
