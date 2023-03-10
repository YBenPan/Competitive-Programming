#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int min3(int a, int b, int c)
{
    return min(a, min(b, c)); 
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    int a[105]; 
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int dp[105][3] = {0}; 
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = min3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
        if (a[i] == 1 || a[i] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]); 
        else dp[i][1] = 1E16; 
        if (a[i] == 2 || a[i] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]); 
        else dp[i][2] = 1E16; 
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << min3(dp[n][0], dp[n][1], dp[n][2]) << endl;
    return 0;
}