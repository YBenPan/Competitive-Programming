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
    //freopen("1626D.in", "r", stdin);
    //freopen("1626D.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--)
    {
        int n, in, ans = 1E9;
        cin >> n;
        vi a;
        for (int i = 0; i < n; i++) {cin >> in; a.pb(in);}
        sort(a.begin(), a.end());
        vi cnt;
        cnt.pb(0);
        for (int i = 1; i < n; i++)
            if (a[i] != a[i - 1]) cnt.pb(i); // i - 1 + 1
        cnt.pb(n);
        for (auto x : cnt)
        {
            int ex;
            for (int r = 0; r <= 18; r++)
                if ((1 << r) >= x) {ex = r; break;}
            for (int p = 0; p <= 18; p++)
            {
                auto j = upper_bound(cnt.begin(), cnt.end(), (1 << p) + x);  
                if (j == cnt.begin()) continue;
                j--; 
                int val = *j;
                for (int q = 0; q <= 18; q++)
                {
                    if ((1 << q) < n - val) continue;
                    ans = min(ans, (1<<ex) - x + (1 << p) + x - val + (1 << q) - (n - val));
                    break;
                }
                if (next(j) == cnt.end()) break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}