#include <bits/stdc++.h>
using namespace std;
bool BinarySearch(int val, int arr[], int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid =(l +r) / 2;
        if (arr[mid] == val)
            return true;
        else if (arr[mid] < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    if (BinarySearch(2, arr, n))
        cout << "Found\n";
    else
        cout << "Not Found\n";
    return 0;
}