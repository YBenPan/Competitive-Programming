#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[505][63005] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL target = ((1 + n) * n) / 2; 
    if (target % 2) {cout << 0 << endl; return 0;}
    target /= 2;
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= target; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (i <= j) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
        }
    }
    cout << dp[n - 1][target]  << endl;
    return 0;
}