#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
LL dp[1000005] = {0}; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    int a[105];
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= x; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i >= a[j])
            {
                dp[i] += dp[i - a[j]]; 
                dp[i] %= MOD;
            }
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[x] << endl;
    return 0;
}