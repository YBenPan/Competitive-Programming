#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool visited[2505] = {false};
int n, m;
vector< vector<int> > g(2505);
vector<int> good;
bool dfs(int s)
{
  visited[s] = true;
  if (s == n * m)
    {return true;}
  bool flag = false;
  for (int i = 0; i < g[s].size() && !flag; ++i)
    if (!visited[g[s][i]])
      {
        if (dfs(g[s][i])) {flag = true;}
      }
  if (flag) return true;
  else return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      cin >> n >> m;
      char in[55][55];
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          cin >> in[i][j];
      bool flag = true;
      bool good_person = false;
      for (int i = 1; i <= n; ++i)
        {
          for (int j = 1; j <= m; ++j)
            {
              if (in[i][j] == 'B')
                {
                  if (j + 1 <= m && in[i][j + 1] == '.') in[i][j + 1] = '#';
                  else if (j + 1 <= m && in[i][j + 1] == 'G') flag = false;
                  if (i + 1 <= n && in[i + 1][j] == '.') in[i + 1][j] = '#';
                  else if (i + 1 <= n && in[i + 1][j] == 'G') flag = false;
                  if (j - 1 > 0 && in[i][j - 1] == '.') in[i][j - 1] = '#';
                  else if (j - 1 > 0 && in[i][j - 1] == 'G') flag = false;
                  if (i - 1 > 0 && in[i - 1][j] == '.') in[i - 1][j] = '#';
                  else if (i - 1 > 0 && in[i - 1][j] == 'G') flag = false;
                }
              else if (in[i][j] == 'G') good_person = true;
              //cout << in[i][j];
            }
          //cout << endl;
        }
      if (in[n][m - 1] == 'B' || in[n - 1][m] == 'B')
        {
          if (good_person) flag = false;
          else {cout << "Yes" << endl; continue;}
        }
      if (!flag) {cout << "No" << endl; continue;}

      g.clear();
      good.clear();
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          {
            int index = (i - 1) * m + j;
            //cout << index << " ";
            if (in[i][j] != '#')
              {
                if (in[i][j] == 'G') good.push_back(index);
                if (j + 1 <= m && in[i][j + 1] != '#')
                  {
                    g[index].push_back(index + 1);
                    g[index + 1].push_back(index);
                  }
                if (i + 1 <= n && in[i + 1][j] != '#')
                  {
                    g[index].push_back(index + m);
                    g[index + m].push_back(index);
                    }
                if (j - 1 > 0 && in[i][j - 1] != '#')
                  {
                    g[index].push_back(index - 1);
                    g[index - 1].push_back(index);
                    }
                if (i - 1 > 0 && in[i - 1][j] != '#')
                  {
                    g[index].push_back(index - m);
                    g[index - m].push_back(index);
                  }
              }
            visited[index] = false;
          }
      //for (int i : g[7]) cout << i << " ";
      //cout << endl;
      for (int i = 0; i < good.size() && flag; ++i)
        {
          for (int j = 0; j < 2505; ++j) visited[j] = false;
          if (!dfs(good[i])) {flag = false;}
        }
      if (flag) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

  return 0;
}
