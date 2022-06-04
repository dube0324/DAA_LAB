// Write  a  program  to  sort  the  list of integers  using  heap  sort  with  bottom-up  max  heap construction  and analyze  its  time
// efficiency.  Prove  experimentally  that  the  worst-case  time complexity is O (n log n).
#include <bits/stdc++.h>
using namespace std;
void print(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        print(arr);
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}
void HeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    HeapSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}