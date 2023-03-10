#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int dp[305][10005] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int s, n;
    cin >> s >> n;
    int wt[305]; 
    for (int i = 1; i <= n; ++i) cin >> wt[i]; 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= s; ++j)
        {
            if (wt[i] <= j)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i]] + wt[i]); 
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); 
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}