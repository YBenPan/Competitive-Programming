#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 1000000007
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>

main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    vector<pi> d;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x;
        if (i - x >= 0) d.pb({i - x, x});
    }
    if (d.size() == 0) {cout << 0 << endl; return 0;}
    sort(d.begin(), d.end());
    vector<int> dp(n + 1, 1E9);
    dp[0] = -1E9;
    for (int i = 0; i < d.size(); i++)
    {
        int j = lower_bound(dp.begin(), dp.end(), d[i].se) - dp.begin();
        if (dp[j - 1] <= d[i].se && d[i].se <= dp[j]) dp[j] = d[i].se;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i] < 1E9) ans = i;
    cout << ans << endl;
    return 0;
}