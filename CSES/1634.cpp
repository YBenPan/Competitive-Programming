#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int a[105]; 
int dp[1000005];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i]; 
    dp[0] = 0;
    for (int i = 1; i <= x; ++i)
    {
        dp[i] = 1E9;
        for (int j = 1; j <= n; ++j)
        {
            if (i >= a[j] && dp[i - a[j]] != -1)
            {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
        if (dp[i] == 1E9) dp[i] = -1;
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[x] << endl;
    return 0;
}