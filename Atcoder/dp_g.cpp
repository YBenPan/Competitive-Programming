#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<int> g[100005];
vector<int> ans;
bool visited[100005] = {false};
int dist[100005] = {0};
void topo(int s)
{
  visited[s] = true;
  for (int i = 0; i < g[s].size(); ++i)
    if (!visited[g[s][i]])
      topo(g[s][i]);
  ans.push_back(s);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; ++i)
    {
      cin >> a >> b;
      g[a - 1].push_back(b - 1);
    }
  for (int i = 0; i < N; ++i)
    if (!visited[i])
      topo(i);
  reverse(ans.begin(), ans.end());
  int maxx = 0;
  for (int i = 0; i < ans.size(); ++i)
    {
      //cout << ans[i] << " ";
      int v = ans[i];
      for (int j = 0; j < g[v].size(); ++j)
        {
          int w = g[v][j];
          dist[w] = max(dist[w], dist[v] + 1);
        }
    }
  for (int i = 0; i < N; ++i) maxx = max(maxx, dist[i]);
  cout << maxx << endl;
  return 0;
}
