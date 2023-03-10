#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[10005], in[10005]; 
bool visited[10005] = {0}; 
vi st;
void dfs(int s)
{
    visited[s] = true; 
    for (auto i : g[s])
        if (!visited[i]) dfs(i); 
    st.pb(s); 
}
int main()
{
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int in1, in2;
    for (int i = 0; i < m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
        in[in2].pb(in1);
    }
    //topological sort
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(i); 
    reverse(st.begin(), st.end()); 
    int dp[10005] = {0}, ans = 0; 
    for (int i = 0; i < st.size(); ++i)
    {
        int node = st[i];
        for (auto j : in[node]) dp[node] = max(dp[node], dp[j] + 1); 
        ans = max(ans, dp[node]); 
    }
    cout << ans << endl;
    return 0;
}