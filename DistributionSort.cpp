#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void CountSort(int arr[], int n, int l, int u)
{
    int d[u - l + 1] = {0};
    int output[n];
    for (int i = 0; i < n; i++)
        d[arr[i] - l]++;
    for (int i = 1; i < n; i++)
        d[i] += d[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        int j = arr[i] - l;
        output[d[j] - 1] = arr[i];
        d[j]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
int main()
{
    int n = 5, l = 1, u = 5;
    int arr[n] = {4, 2, 3, 1, 5};
    printArray(arr, n);
    CountSort(arr, n, l, u);
    printArray(arr, n);
    return 0;
}