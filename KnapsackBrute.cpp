#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets;
void GenerateAllSubsets(int *arr, int i, int n, int *subset, int j)
{
    vector<int> v;
    if (i == n)
    {
        int idx = 0;
        while (idx < j)
        {
            v.push_back(subset[idx]);
            ++idx;
        }
        subsets.push_back(v);
        return;
    }
    GenerateAllSubsets(arr, i + 1, n, subset, j);
    subset[j] = arr[i];
    GenerateAllSubsets(arr, i + 1, n, subset, j + 1);
}
int main()
{
    cout << "Enter max weight of knapsack: ";
    int maxWeight, n;
    cin >> maxWeight;
    cout << "Enter the number of items in the knapsack: ";
    cin >> n;
    int subset[100];
    int num[n], weight[n], profit[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weight[i];
        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> profit[i];
        num[i] = i + 1;
    }
    GenerateAllSubsets(num, 0, n, subset, 0);
    int MaxSoFar = -INT_MAX, flag;
    for (int i = 0; (i < subsets.size()); i++)
    {
        int cost = 0, currW = 0;
        for (int j = 0; (j < subsets[i].size()); j++)
        {
            currW += weight[(subsets[i][j]) - 1];
            cost += profit[(subsets[i][j]) - 1];
            if ((cost > MaxSoFar) && (currW <= maxWeight))
            {
                MaxSoFar = cost;
                flag = i;
            }
        }
    }
    if (MaxSoFar < 0)
    {
        cout << "Nothing can fit in knapsack.";
        return 0;
    }
    cout << "Maximum profit possible in knapsack: " << MaxSoFar << endl;
    cout << "Subset of items used: ";
    for (int i = 0; i < subsets[flag].size(); i++)
        cout << subsets[flag][i] << " ";
}