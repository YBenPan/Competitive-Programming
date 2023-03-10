#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector< vector<int> > g(100005);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int u, v;
  for (int i = 1; i < n; ++i)
    {
      cin >> u >> v;
      g[u].push_back(i);
      g[v].push_back(i);
    }
  int index = 0;
  for (int i = 1; i <= n; ++i)
    if (g[i].size() >= 3)
      {
        index = i;
        break;
      }
  int ans[100005] = {0};
  int cnt = 0;
  for (int i = 0; i < g[index].size(); ++i)
    ans[g[index][i]] = ++cnt;
  for (int i = 1; i <= n - 1; ++i)
    {
      if (ans[i] == 0)
        ans[i] = ++cnt;
      cout << ans[i] - 1 << endl;
    }
  return 0;
}
