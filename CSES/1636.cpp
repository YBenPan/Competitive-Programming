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
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (j >= a[i])
            {
                dp[j] += dp[j - a[i]]; 
                dp[j] %= MOD;
            }
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[x] << endl;
    return 0;
}