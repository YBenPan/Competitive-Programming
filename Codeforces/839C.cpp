#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector< vector<int> > g(100005);
bool visited[100005] = {false};
double dfs(int s)
{
  visited[s] = true;
  double sum = 0;
  if (g[s].size() == 1 && s != 1)
    return 0;
  int cnt = 0;
  for (int i = 0; i < g[s].size(); ++i)
    if (!visited[g[s][i]])
      {
        cnt++;
        sum += dfs(g[s][i]);
      }
  //cout << s << " " << sum << endl;
  return (sum / cnt) + 1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int u, v;
  if (n == 1)
    {
      cout << 0 << endl;
      return 0;
    }
  for (int i = 0; i < n - 1; ++i)
    {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  cout << setprecision(7) << dfs(1) << endl;
  return 0;
}
