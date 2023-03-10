#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[100005], ans;
bool visited[100005] = {0}; 
int ind[100005];
pi edge[200005];  
void dfs(int s)
{
    for (auto i : g[s])
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i); 
        }
    ans.pb(s); 
    ind[s] = ans.size() - 1; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> edge[i].first >> edge[i].second;
        g[edge[i].first].pb(edge[i].second); 
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i); 
        }
    }
    reverse(ans.begin(), ans.end());
    bool valid = true; 
    for (int i = 1; i <= m && valid; ++i)
    {
        int st = edge[i].first, ed = edge[i].second; 
        if (ind[st] <= ind[ed]) valid = false; 
    }
    if (!valid) cout << "IMPOSSIBLE";
    else for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}