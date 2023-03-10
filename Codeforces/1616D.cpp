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
int a[50005], pre[500005], dp[50005][2], last[50005];
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--)
    {
        int n, x;
        cin >> n;
        pre[0] = 0;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        cin >> x;
        for (int i = 1; i <= n; i++)
        {
            a[i] -= x;
            pre[i] = pre[i - 1] + a[i];
        }
        dp[0][0] = 0; dp[0][1] = 0;
        last[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = 0; dp[i][0] = 0;
            if (pre[i] - pre[last[i - 1] - 1] >= 0)
            {
                dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
                if (pre[i] - pre[last[i - 1] - 1] > a[i])
                    last[i] = i;
                else last[i] = last[i - 1];
            }
            if (dp[i - 1][0] + 1 >= dp[i][1])
            {
                dp[i][1] = dp[i - 1][0] + 1;
                last[i] = i;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}