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
pi ord(int a, int b)
{
    if (a > b) return {b, a};
    return {a, b};
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, in1, in2, ans = 0;
        cin >> n >> m;
        map<int, vi> eq; 
        map<int, int> cnt;
        vector<pi> bad;
        for (int i = 1; i <= n; i++)
        {
            cin >> in1;
            cnt[in1]++;
        }        
        for (int i = 1; i <= m; i++)
        {
            cin >> in1 >> in2;
            bad.pb(ord(in1, in2));
        }
        for (auto i : cnt)
        {
            int key = i.fi, val = i.se;
            eq[val].pb(key);
        }
        for (auto &i : eq)
            reverse(i.se.begin(), i.se.end());
        sort(bad.begin(), bad.end());
        for (auto [cnt_x, v1] : eq)
            for (auto [cnt_y, v2] : eq)
            {
                if (cnt_x < cnt_y) break;
                for (auto x : v1)
                    for (auto y : v2)
                        if (x != y && !binary_search(bad.begin(), bad.end(), ord(x, y)))
                        {
                            ans = max(ans, (cnt_x + cnt_y) * (x + y));
                            break;
                        }
            }
        cout << ans << "\n";
    }
    return 0;
}