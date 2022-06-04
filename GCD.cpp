#include <bits/stdc++.h>
using namespace std;
int c1=0;
int c2=0;
int gcdBrute(int a, int b)
{
    c1++;
    cout<<"c1: "<<c1<<endl;
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcdBrute(a-b,b);
    return gcdBrute(a,b-a);
}
int gcdEuclid(int a, int b)
{
    c2++;
    cout<<"c2: "<<c2<<endl; 
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int a = 50, b = 15;
    cout << gcdBrute(a, b)<<endl;  //O(min(a,b))
    cout << gcdEuclid(a, b);  //O(log(min(a,b))    
    return 0;
}