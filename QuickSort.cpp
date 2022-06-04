#include <bits/stdc++.h>
using namespace std;
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}
int main()
{
    int n = 5;
    int arr[n] = {4, 3, 2, 1, 5};
    QuickSort(arr, 0, n - 1);
    printarray(arr, n);
    return 0;
}