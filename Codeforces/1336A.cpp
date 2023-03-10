#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> g[200006];
int opt[200006] = {0};
int dfs(int source, int last, int depth)
{
  int size = 1;
  for (int i = 0; i < g[source].size(); ++i)
    {
      if (g[source][i] == last) continue;
      int res = dfs(g[source][i], source, depth + 1);
      size += res;
    }
  //cout << source << " " << size << " " << depth << endl;
  opt[source] = size - depth;
  return size;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  int u, v;
  for (int i = 1; i <= n - 1; ++i)
    {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  dfs(1, 0, 1);
  sort(opt + 1, opt + n + 1, greater<int>());
  long long ans = 0;
  for (int i = 1; i <= n - k; ++i)
    ans += opt[i];
  cout << ans << endl;
  return 0;
}
