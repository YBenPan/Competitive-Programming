#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[1005][1005] = {0};
char ch[1005][1005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> ch[i][j];
    if (ch[1][1] == '.') dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (ch[i][j] == '*') continue;
            if (i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD; 
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}