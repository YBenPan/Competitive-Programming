#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector< vector<int> > g(100005);
vector<int> part1, part2;
int visited[100005] = {0};
list<int> q;
bool dfs(int vertex, int color)
{
  visited[vertex] = color;
  if (color == 1) part1.push_back(vertex);
  else part2.push_back(vertex);
  for (int i = 0; i < g[vertex].size(); ++i)
    {
      //cout << i << " " << g[vertex][i] << endl;
      if (visited[g[vertex][i]] == 0 && !dfs(g[vertex][i], -color))
        return false;
      if (visited[g[vertex][i]] == color)
        return false;
    }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; ++i)
    {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  for (int i = 1; i <= n; ++i)
    {
      if (visited[i] == 0 && g[i].size() != 0)
        {
          bool flag = dfs(i, 1);
          if (!flag)
            {
              cout << -1 << endl;
              return 0;
            }
        }
    }
  cout << part1.size() << endl;
  for (int i = 0; i < part1.size(); ++i)
    cout << part1[i] << " ";
  cout << endl;
  cout << part2.size() << endl;
  for (int i = 0; i < part2.size(); ++i)
    cout << part2[i] << " ";
  cout << endl;
  return 0;
}
