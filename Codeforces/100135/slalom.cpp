#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>

int main()
{
    //freopen("slalom.in", "r", stdin);
    //freopen("slalom.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[105][105], dp[105][105]; 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j]; 
        }
    }
    dp[1][1] = a[1][1]; 
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (j == 1) dp[i][j] = dp[i - 1][j];
            else if (j == i) dp[i][j] = dp[i - 1][j - 1]; 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            dp[i][j] += a[i][j]; 
        }
    }
    int ans = -1E9; 
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[n][i]); 
    cout << ans << endl;
    return 0;
}