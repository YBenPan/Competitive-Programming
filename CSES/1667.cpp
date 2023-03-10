#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[100005]; 
int parent[100005]; 
int dist[100005];
vi ans; 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m;
    int in1, in2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2);
        g[in2].pb(in1); 
    } 
    queue<int> q;
    q.push(1); 
    dist[1] = 0;
    while (!q.empty())
    {
        int t = q.front(); 
        q.pop();
        for (auto i : g[t])
        {
            if (dist[i] > dist[t] + 1)
            {
                parent[i] = t;
                q.push(i);
                dist[i] = dist[t] + 1;
            }
        }
    }
    //cout << dist[n] << endl;
    if (dist[n] > m) 
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int node = n;
    while (node != 1)
    {
        ans.pb(node);
        node = parent[node]; 
    }
    ans.pb(1);
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end()); 
    for (auto i : ans) cout << i << " ";
    return 0;
}