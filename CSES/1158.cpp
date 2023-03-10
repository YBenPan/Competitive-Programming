#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[1005][100005] = {0}; 
int w[1005], v[1005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> w[i]; 
    for (int i = 1; i <= n; ++i) cin >> v[i]; 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= x; ++j)
        {
            dp[i][j] = dp[i - 1][j]; 
            if (w[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); 
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}