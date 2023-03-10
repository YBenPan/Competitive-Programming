#include <bits/stdc++.h>
using namespace std;
string str[505];
int n, m, k;
bool visited[505][505] = {false};
void dfs(int p, int q)
{
  if (p < 0 || p >= n || q < 0 || q >= m)
    return;
  if (visited[p][q])
    return;
  if (str[p][q] != '.')
    return;
  visited[p][q] = true;
  dfs(p, q + 1);
  dfs(p, q - 1);
  dfs(p + 1, q);
  dfs(p - 1, q);
  if (k > 0)
    {
      k--;
      str[p][q] = 'X';
    }
  else return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> str[i];
  for (int i = 0; i < n && k > 0; ++i)
    for (int j = 0; j < m && k > 0; ++j)
      dfs(i, j);
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
        cout << str[i][j];
      cout << endl;
    }
  return 0;
}
