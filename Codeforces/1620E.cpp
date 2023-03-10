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
int n = 0;
int col[500005], rt[500005], pa[500005], depth[500005];
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
    if (depth[a] < depth[b]) pa[a] = b;
    else
    {
        pa[b] = a;
        depth[a] = max(depth[a], depth[b] + 1);
    }
}
main()
{   
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    int type, x, y;
    memset(col, -1, sizeof(col));
    memset(pa, -1, sizeof(pa));
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            n++;
            pa[n] = n;
            depth[n] = 1;
            if (col[x] > -1) // parent of same color exists
                join(col[x], n);
            else
            {
                col[x] = n;
                rt[n] = x;
            }
        }
        else
        {
            cin >> x >> y;
            if (col[x] == -1) continue;
            if (x == y) continue;
            if (col[y] > -1)
            {
                join(col[x], col[y]);
                col[y] = findRoot(col[y]);
            }
            else
                col[y] = col[x];
            col[x] = -1;
            rt[col[y]] = y;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int r = findRoot(i);
        cout << rt[r] << " ";
    }
    return 0;
}