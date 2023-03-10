#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g(205);
int n, m;
bool visited[205] = {false};
void DFS_Util(int s)
{
  visited[s] = true;
  for (int i = 0; i < (int)g[s].size(); ++i)
    if (!visited[g[s][i]])
      DFS_Util(g[s][i]);
}
int DFS()
{
  int tot = 0;
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      {
        DFS_Util(i);
        tot++;
      }
  return tot - 1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  int k;
  int input;
  bool flag = true;
  for (int i = 0; i < n; ++i)
    {
      cin >> k;
      if (k != 0) flag = false;
      for (int j = 0; j < k; ++j)
        {
          cin >> input;
          g[i].push_back(input + n);
          g[input + n].push_back(i);
        }
    }
  if (!flag)
    cout << DFS() << endl;
  else
    cout << n << endl;
  return 0;
}
