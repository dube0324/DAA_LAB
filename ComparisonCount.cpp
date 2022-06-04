#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void CountSort(int arr[], int n)
{
    int count[n] = {0};
    int s[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
                count[j]++;
            else
                count[i]++;
        }
    }
    for (int i = 0; i < n; i++)
        s[count[i]] = arr[i];
    for (int i = 0; i < n; i++)
        arr[i] = s[i];
}
int main()
{
    int n = 5;
    int arr[n] = {4, 2, 3, 1, 5};
    printArray(arr, n);
    CountSort(arr, n);
    printArray(arr, n);
    return 0;
}