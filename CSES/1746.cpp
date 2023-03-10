#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[100005][105] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[100005]; 
    for (int i = 1; i <= n; ++i) cin >> a[i]; 
    if (a[1]) dp[1][a[1]] = 1;
    else for (int i = 1; i <= m; ++i) dp[1][i] = 1; 
    for (int i = 2; i <= n; ++i)
    {
        if (a[i]) dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
        else
        {
            for (int j = 1; j <= m; ++j)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        }
    }
    LL sum = 0;
    for (int i = 1; i <= m; ++i) sum = (sum + dp[n][i]) % MOD;
    cout << sum << endl;
    return 0;
}