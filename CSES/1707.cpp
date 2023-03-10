#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[2505];  
int dist[2505], parent[2505], ans = 1E9;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int x1, y1;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x1 >> y1;
        g[x1].pb(y1); 
        g[y1].pb(x1); 
    }
    for (int i = 1; i <= n; ++i)
    {
        queue<int> q; 
        memset(dist, 0x3f, sizeof(dist)); 
        memset(parent, -1, sizeof(parent));
        q.push(i); 
        dist[i] = 0;
        while (!q.empty())
        {
            int t = q.front(); q.pop();
            for (auto child : g[t])
            {
                if (dist[child] > 1E8) //not visited
                {
                    dist[child] = dist[t] + 1;
                    parent[child] = t;
                    q.push(child); 
                }
                else if (parent[t] != child) //there is a cycle and no backtracking
                {
                    ans = min(ans, dist[t] + dist[child] + 1); 
                }
            }
        }
    }
    if (ans > 1E8) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}