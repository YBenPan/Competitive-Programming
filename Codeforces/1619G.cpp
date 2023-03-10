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
struct bomb
{
    int x, y, i, t;
};
bool cmp1(bomb a, bomb b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(bomb a, bomb b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
vector<bomb> c1, c2;
int pa[200005], depth[200005], cc[200005];
int findRoot(int a)
{
    if (pa[a] == a) return a;
    return pa[a] = findRoot(pa[a]);
}
void join(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;
    if (depth[a] < depth[b])
    {
        pa[a] = b;
        cc[b] = min(cc[b], cc[a]);
        cc[a] = -1;
    }
    else
    {
        pa[b] = a;
        depth[a] = max(depth[a], depth[b] + 1);
        cc[a] = min(cc[a], cc[b]);
        cc[b] = -1;
    }
}
main()
{
    //freopen("1619G.in", "r", stdin);
    //freopen("1619G.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(pa, 0, sizeof(pa));
        memset(depth, 0, sizeof(depth));
        memset(cc, 0, sizeof(cc));
        c1.clear();
        c2.clear();
        //string tmp;
        //getline(cin, tmp);
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) 
        {
            c1.push_back({});
            cin >> c1[i].x >> c1[i].y >> c1[i].t;
            depth[i] = 1;
            pa[i] = i;
        }
        sort(c1.begin(), c1.end(), cmp1);
        for (int i = 0; i < n; i++)
        {
            c1[i].i = i;
            cc[i] = c1[i].t;
            //cout << c1[i].x << " " << c1[i].y << endl;
            c2.pb(c1[i]);
        }   
        sort(c2.begin(), c2.end(), cmp2);
        for (int i = 0; i < n - 1; i++)
        {
            if (c1[i].x == c1[i + 1].x && c1[i + 1].y - c1[i].y <= k)
                join(i, i + 1);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (c2[i].y == c2[i + 1].y && c2[i + 1].x - c2[i].x <= k)
                join(c2[i].i, c2[i + 1].i);
        }
        vi time;
        for (int i = 0; i < n; i++) 
        {
            // int rt = findRoot(i);
            // cout << i << " " << rt << " " << cc[i] << endl;
            if (cc[i] > -1) time.pb(cc[i]);
        }
        sort(time.begin(), time.end());
        int ans = time.size() - 1;
        for (int i = 0; i < time.size(); i++)
        {
            //cout << time[i] << " ";
            ans = min(ans, max(time[i], time.size() - i - 2));
        }
        cout << ans << endl;
    }   
    return 0;
}