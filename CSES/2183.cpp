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
int a[200005], dp[200005];
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > dp[i - 1]) {cout << dp[i - 1] << endl; return 0;}
        dp[i] = dp[i - 1] + a[i];
    }
    cout << dp[n] << endl;
    return 0;
}