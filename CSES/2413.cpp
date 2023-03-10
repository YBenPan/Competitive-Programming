#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL a[1000005], b[1000005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a[1] = 1; b[1] = 1; 
        for (int i = 2; i <= n; ++i)
        {
            a[i] = (a[i - 1] * 4 + b[i - 1]) % MOD;
            b[i] = (2 * b[i - 1] + a[i - 1]) % MOD;
        }
        cout << (a[n] + b[n]) % MOD << endl;
    }
    return 0;
}