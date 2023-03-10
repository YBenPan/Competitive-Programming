#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL sumA = 0, sumG = 0;
    LL input1, input2;
    for (int i = 0; i < n; ++i)
    {
        cin >> input1 >> input2;
        if (abs(sumG - (sumA + input1)) <= 500) 
        {
            cout << "A";
            sumA += input1;
        }
        else
        {
            cout << "G";
            sumG += input2;
        }
    }
    return 0;
}