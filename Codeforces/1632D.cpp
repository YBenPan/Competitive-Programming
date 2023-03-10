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
int n;
int a[200005], t[800005];
vi seg[200005]; 
void build(int v, int tl, int tr)
{
    if (tl == tr) t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
    }
}
int get(int v, int tl, int tr, int l, int r)
{
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return __gcd(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1, val = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int gcdv = get(1, 0, n - 1, i, mid); 
            if (gcdv >= mid - i + 1) 
            {
                val = mid; 
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (get(1, 0, n - 1, i, val) == val - i + 1)  // BAD 
            seg[val].pb(i);
    }
    int cnt = 0, max_r = -1;
    for (int i = 0; i < n; i++)
    {
        for (auto j : seg[i]) 
            if (j > max_r) 
            {
                max_r = i;
                cnt++;
            }
        cout << cnt << " ";
    }
    return 0;
}