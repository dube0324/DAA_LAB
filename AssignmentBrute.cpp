#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> permutations;
void GeneratePerm(vector<int> &num, int begin, vector<vector<int>> &result)
{
    if (begin >= num.size())
    {
        result.push_back(num);
        return;
    }
    for (int i = begin; i < num.size(); i++)
    {
        swap(num[begin], num[i]);
        GeneratePerm(num, begin + 1, result);
        swap(num[begin], num[i]);
    }
}
int main()
{
    int n;
    cout << "Enter the number of workers/jobs: ";
    cin >> n;
    int costMatrix[n][n];
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter cost of worker " << i + 1 << " for job " << j + 1 << ": ";
            cin >> costMatrix[i][j];
        }
        num.push_back(i + 1);
    }
    GeneratePerm(num, 0, permutations);
    int flag, minSoFar = INT_MAX;
    for (int i = 0; i < permutations.size(); i++)
    {
        int cost = 0, count = 0;
        for (int j = 0; j < permutations[i].size(); j++)
        {
            cost += costMatrix[count++][(permutations[i][j]) - 1];
        }
        if (cost < minSoFar)
        {
            minSoFar = cost;
            flag = i;
        }
    }
    cout << "Mimimum cost possible: " << minSoFar << endl;
    cout << "Job assignment used: ";
    for (int i = 0; i < permutations[flag].size(); i++)
        cout << permutations[flag][i] << " ";
}
