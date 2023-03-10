#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
bool dp[105][100005] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int w[105];
    for (int i = 1; i <= n; ++i) 
    {
        cin >> w[i];
        dp[i][w[i]] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 100000; ++j)
        {
            dp[i][j] |= dp[i - 1][j];
            if (w[i] <= j)
            {
                dp[i][j] |= dp[i - 1][j - w[i]]; 
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    vi ans; 
    for (int i = 1; i <= 100000; i++)
        if (dp[n][i]) ans.pb(i); 
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
    return 0;
}