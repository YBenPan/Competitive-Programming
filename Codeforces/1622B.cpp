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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[200005];
        for (int i = 0; i < n; i++) cin >> a[i];
        string str;
        cin >> str;   
        vector<pi> p, q;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0') q.pb(make_pair(a[i], i));
            else p.pb({a[i], i});
        }
        
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        // for (int i = 0; i < q.size(); i++) cout << q[i].fi << " " << q[i].se << endl;
        int tot = 0;
        
        for (int i = 0; i < q.size(); i++)
        {
            int tm = i + 1;
            //cout << q[i].se << endl;
            a[q[i].se] = tm;
        }
        for (int i = 0; i < p.size(); i++)
        {
            int tm = i + q.size() + 1;
            a[p[i].se] = tm;
        }
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}