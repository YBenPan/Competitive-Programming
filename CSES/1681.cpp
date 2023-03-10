#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[100005];
bool visited[100005] = {0};
LL node_sum[100005] = {0};
vi topo_order;
void dfs(int s)
{
    visited[s] = true; 
    for (auto i : g[s])
        if (!visited[i])
            dfs(i);         
    topo_order.pb(s); 
}
void topo_sum(int s)
{
    visited[s] = 1;
    for (auto i : g[s])
    {
        if (!visited[i]) 
            topo_sum(i); 
        node_sum[s] = (node_sum[s] + node_sum[i]) % MOD;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int in1, in2;
    for (int i = 0; i < m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
    }
    dfs(1); 
    reverse(topo_order.begin(), topo_order.end()); 
    memset(visited, 0, sizeof(visited)); 
    visited[n] = node_sum[n] = 1; 
    topo_sum(1); 
    cout << node_sum[1] << endl;
    return 0;
}