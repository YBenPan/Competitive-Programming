#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<short> a(100001);
vector<vector<int>> g(100001);
bool visited[100005] = {false};
int tot = 0;
void dfs(int k, int index)
{
  visited[index] = true;
  int sum = 0;
  if (k > m)
    return;
  bool flag = true;
  for (int i = 0; i < g[index].size(); ++i)
    {
      if (!visited[g[index][i]])
        {
          visited[g[index][i]] = true;
          if (a[g[index][i]] == 1)
            sum = k + 1;
          else
            sum = 0;
          dfs(sum, g[index][i]);
          //cout << sum << " " << index << " " << g[index][i] << endl;
          flag = false;
        }
    }
  if (flag)
    {
      tot++;
      //cout << index << endl;
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  short input;
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      a[i] = input;
    }
  int x, y;
  for (int i = 0; i < n - 1; ++i)
    {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  dfs(a[1], 1);
  cout << tot << endl;
  return 0;
}
