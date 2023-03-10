#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[505][505]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int a, b, c;
    memset(dp, 0x3f3f3f3f, sizeof(dp)); 
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        if (dp[a][b] > c) dp[a][b] = dp[b][a] = c;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        if (dp[a][b] >= 1E18) 
            cout << -1 << endl;
        else if (a == b)
            cout << 0 << endl;
        else 
            cout << dp[a][b] << endl;
    }
    return 0;
}