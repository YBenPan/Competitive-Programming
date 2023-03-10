#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[1000005] = {0}; 
int main()
{
    freopen("joseph.in", "r", stdin);
    freopen("joseph.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p;
    cin >> n >> p;
    
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + p) % i; 
    }
    cout << dp[n] + 1 << endl;
    return 0;
}