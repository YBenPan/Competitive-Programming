#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int dp[55][55] = {0}; 
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j > 1 && i > 0) dp[i][j] += dp[i - 1][j - 2]; 
            if (j > 0 && i > 1) dp[i][j] += dp[i - 2][j - 1]; 
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[m - 1][n - 1] << endl;
    return 0;
}