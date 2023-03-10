#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[200005]; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL n, m;
    cin >> n >> m;
    LL sum = 3;
    dp[2] = 2; 
    dp[1] = 1;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = sum % m;
        for (int j = 2; floor(1.0 * i / j) > floor(sqrt(i)); ++j)
        {
            int index = floor(1.0 * i / j);
            dp[i] = (dp[i] + dp[index]) % m;
        }
        for (int j = floor(sqrt(i)); j >= 1; --j)
        {
            int lower = floor(1.0 * i / (j + 1)) + 1;
            int upper = floor(1.0 * i / j);
            LL cnt = upper - lower + 1;
            dp[i] = (dp[i] + cnt * dp[j]) % m;
        }
        sum = (sum + dp[i]) % m;
        // cout << i << " " << dp[i] << " " << sum << endl;
    }
    cout << dp[n] << endl;
    return 0;
}