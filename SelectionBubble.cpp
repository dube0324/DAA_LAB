#include <bits/stdc++.h>
using namespace std;
void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void SelectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
        {
            int min_idx=arr[i];
            for(int j=i+1;j<n;j++)
                {
                    if(arr[j]<min_idx)
                        {
                            min_idx = arr[j];
                            swap(arr[i],arr[j]);
                        }
                }
        }
    printarray(arr, n);
}
void BubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
                {
                    if(arr[j]>arr[j+1])
                        {
                            swap(arr[j],arr[j+1]);
                        }
                }
        }
    printarray(arr, n);
}
int main()
{
    int n=5;
    int arr1[5] = {4, 3, 2, 1, 5};
    cout<<"Selection sort:\n";
    printarray(arr1, n);
    SelectionSort(arr1,n);
    int arr2[5] = {4, 3, 2, 1, 5};
    cout<<"Bubble sort:\n";
    printarray(arr2, n);
    BubbleSort(arr2,n);
    return 0;
}