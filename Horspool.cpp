#include <bits/stdc++.h>
using namespace std;
bool Horspool(string text, string pattern)
{
    unordered_map<char, int> Table;
    int n = text.length();
    int m = pattern.length();
    for (char ch = 'A'; ch <= 'z'; ch++)
        Table[ch] = m;
    for (int i = 0; i < m - 1; i++)
        Table[pattern[i]] = m - i - 1;
    // for (auto it : Table)
    //     cout << it.first << " " << it.second << endl;
    int i = m - 1;
    while (i <= n - 1)
    {
        int k = 0;
        while (k <= m - 1 && pattern[m - 1 - k] == text[i - k])
            k++;
        if (k == m)
            return true;
        else
            i += Table[text[i]];
    }
    return 0;
}
int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    int result = Horspool(text, pattern);
    cout << (result == 0 ? "Pattern not found" : "Pattern found") << endl;
}