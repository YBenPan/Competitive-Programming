#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector< vector<int> > g(500005);
vector<pair<int, int>> t;
vector<int> ans;
int mx[500005] = {0};
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
  if (a.second == b.second) return (a.first < b.first);
  return (a.second < b.second);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; ++i)
    {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  for (int i = 1; i <= n; ++i)
    {
      cin >> x;
      t.push_back({i, x});
    }
  sort(t.begin(), t.end(), cmp);
  for (int i = 0; i < n; ++i)
    {
      int index = t[i].first;
      int val = t[i].second;
      if (mx[index] != val - 1)
        {
          cout << -1 << endl;
          return 0;
        }
      ans.push_back(index);
      for (int j = 0; j < g[index].size(); ++j)
        {
          if (mx[g[index][j]] == val - 1)
            mx[g[index][j]] = val;
        }
    }
  for (int i : ans) cout << i << " ";
  cout << endl;
  return 0;
}
