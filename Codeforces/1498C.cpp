#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[1005][1005][2], pre[1005][1005], suf[1005][1005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        memset(dp, 0, sizeof(dp)); 
        memset(pre, 0, sizeof(pre)); 
        memset(suf, 0, sizeof(suf)); 
        for (int j = 1; j <= n; ++j)
        {
            for (int kk = 0; kk <= 1; ++kk)
                dp[1][j][kk] = 1; 
            pre[1][j] = j; 
            suf[1][j] = n - j + 1; 
        }
        for (int i = 2; i < k; ++i)
        {
            dp[i][1][0] = 1; 
            dp[i][n][1] = 1; 
            for (int j = 1; j <= n; ++j)
            {
                if (j > 1) dp[i][j][0] = (pre[i - 1][j - 1] + 1) % MOD; 
                if (j < n) dp[i][j][1] = (suf[i - 1][j + 1] + 1) % MOD; 
            }
            pre[i][0] = 0;
            suf[i][n + 1] = 0;
            for (int j = 1; j <= n; ++j)
            {
                int jj = n - j + 1; 
                pre[i][j] = (pre[i][j - 1] + dp[i][j][1]) % MOD; 
                suf[i][jj] = (suf[i][jj + 1] + dp[i][jj][0]) % MOD; 
            }
        }
        cout << (pre[k - 1][n] + 1) % MOD << endl;
    }
    return 0;
}