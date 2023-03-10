#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector< vector<int> > g(500005);
bool visited[500005] = {false};
int t[500005];
int assigned[500005] = {0};
vector<int> output;
void comp()
bool dfs(int s)
{
  visited[s] = true;
  output.push_back(s);
  int minn = 1;
  set<int> tmp;
  vector< pair<int, int> > link; // first: t second: index
  for (int i = 0; i < g[s].size(); ++i)
    {
      if (assigned[g[s][i]] != 0) tmp.insert(assigned[g[s][i]]);
      if (!visited[g[s][i]])
        {
          //if (!dfs(g[s][i])) {/*cout << s << " " << g[s][i] << endl;*/ return false;}
          link.push_back({t[g[s][i]], g[s][i]});
        }
    }
  sort(link.begin(), link.end(), comp);
  if (assigned[s] == 0)
    {
      for (auto i : tmp)
        if (minn == i) minn++;
        else break;
      assigned[s] = minn;
      cout << s << " " << assigned[s] << endl;
      if (assigned[s] == t[s]) return true;
      else return false;
    }
  else
    return true;
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
  vector<int> index;
  for (int i = 1; i <= n; ++i)
    {
      cin >> t[i];
      if (t[i] == 1) index.push_back(i);
    }
  for (int i = 0; i < index.size(); ++i)
    {
      assigned[index[i]] = 1;
      if (!dfs(index[i]))
        {
          cout << -1 << endl;
          return 0;
        }
    }
  /*
  for (int i = 1; i <= n; ++i)
    if (!visited[i])
      {
        if (!dfs(i))
          {
            cout << -1 << endl;
            return 0;
          }
      }
  */
  for (auto i : output) cout << i << " ";
  cout << endl;
  return 0;
}
