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
bool a[1000005] = {0};
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, in, maxx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> in;
        a[in] = 1;
        maxx = max(maxx, in);
    }
    int ans = 0;
    for (int i = 1; i <= maxx; i++)
    {
        if (a[i]) continue;
        int val = -1;
        for (int j = 2 * i; j <= maxx; j += i)
            if (a[j])
            {
                if (val < 0) val = j;
                else val = __gcd(val, j);
            }
        if (i == val) ans++;
    }
    cout << ans << endl;
    return 0;
}