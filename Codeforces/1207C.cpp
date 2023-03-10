#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
int dp[200005][4]; 
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;
        memset(dp, 0, sizeof(dp)); 
        // dp[0][0] = dp[0][1] = b;
        // dp[0][2] = dp[0][3] = 1E18; 
        dp[1][0] = a + 2 * b; 
        dp[1][1] = 2 * a + 3 * b; 
        dp[1][2] = dp[1][3] = 1E18; 
        for (int i = 2; i <= n; ++i)
        {
            dp[i][3] = min(dp[i - 1][1], dp[i - 1][3]) + a + 2 * b;
            if (str[i - 1] == '1')
            {
                dp[i][0] = 1E18; 
                dp[i][1] = 1E18;
                dp[i][2] = 1E18; 
            }
            else 
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][2]) + a + b;
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + 2 * a + 2 * b;
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + 2 * a + b;
            }
            // for (int j = 0; j < 4; ++j) cout << dp[i][j] << " ";
            // cout << endl;
        }
        cout << min(dp[n][0], dp[n][2]) << endl;
        // cout << ans << endl;
    }   
    return 0;
}