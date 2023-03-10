#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[100005], topo_sort; 
bool visited[100005]; 
int dp[100005] = {0}, parent[100005]; 
void dfs(int s)
{
    for (auto i : g[s])
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i); 
        }
    topo_sort.pb(s);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int in1, in2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
    }
    dfs(1); 
    if (!visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    reverse(topo_sort.begin(), topo_sort.end()); 
    dp[1] = 1; 
    for (auto i : topo_sort)
        for (auto j : g[i]) 
            if (dp[i] + 1 > dp[j])
            {
                dp[j] = dp[i] + 1;
                parent[j] = i;
            }
    vi ans;
    int cur = n; 
    while (cur != 1) 
    {
        ans.pb(cur); 
        cur = parent[cur];
    }
    ans.pb(1);
    reverse(ans.begin(), ans.end()); 
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
    return 0;
}   