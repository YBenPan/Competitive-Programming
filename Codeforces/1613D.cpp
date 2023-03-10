#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define MOD 998244353
#define int LL
#define vi vector<long long>
#define pi pair<long long, long long>
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi dp1(n + 5), dp2(n + 2), a(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        dp1[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int x = a[i];
            if (x > 0) dp2[x - 1] = (dp2[x - 1] + dp2[x - 1] + dp1[x - 1]) % MOD;
            dp2[x + 1] = (dp2[x + 1] + dp2[x + 1]) % MOD;
            dp1[x + 1] = (dp1[x + 1] + dp1[x + 1] + dp1[x]) % MOD;
        }
        int sum = 0;
        for (int i = 0; i <= n; i++) 
        {
            sum = (sum + dp1[i] + dp2[i]) % MOD;
        }
        int ans = sum - 1;
        if (ans < 0) ans += MOD;
        cout << ans % MOD << endl;
    }
    return 0;
}