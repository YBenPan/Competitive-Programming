#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n;
vi g[200005]; 
pi bfs(int s)
{
    int visited[200005] = {0}; 
    queue<pi> q;
    q.push({s, 0}); 
    visited[s] = true; 
    int maxx = 0, max_node = s; 
    while (!q.empty())
    {
        pi t = q.front(); q.pop(); 
        int node = t.first; 
        visited[node] = true; 
        if (t.second > maxx) {maxx = t.second; max_node = node;}
        for (auto i : g[node])
        {
            if (!visited[i]) q.push({i, t.second + 1}); 
        }
    }
    return {maxx, max_node};
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int in1, in2;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> in1 >> in2; 
        g[in1].pb(in2); 
        g[in2].pb(in1); 
    }
    pi res = bfs(1); 
    pi res1 = bfs(res.second); 
    cout << res1.first << endl;
    return 0;
}