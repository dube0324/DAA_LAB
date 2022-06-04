#include <bits/stdc++.h>
using namespace std;
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int n = 5;
    int arr[n] = {4, 2, 3, 1, 5};
    printarray(arr, n);
    InsertionSort(arr, n);
    printarray(arr, n);
    return 0;
}
