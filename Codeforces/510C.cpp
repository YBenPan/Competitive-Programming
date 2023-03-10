#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<int> g[26];
int in[26];
int ans[26];
int tot = 0;
void toposort()
{
  queue<int> q;
  for (int i = 0; i < 26; ++i) if (in[i] == 0) q.push(i);
  while (!q.empty())
    {
      int x = q.front();
      ans[tot++] = x;
      q.pop();
      for (int i = 0; i < g[x].size(); ++i)
        {
          in[g[x][i]]--;
          if (in[g[x][i]] == 0)
            {
              q.push(g[x][i]);
            }
        }
    }
  if (tot != 26) cout << "Impossible" << endl;
  else
    {
      for (int i = 0; i < 26; ++i)
        cout << (char)(ans[i] + 'a');
      cout << endl;
    }
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<string> vec(n);
  for (int i = 0; i < n; ++i) cin >> vec[i];
  for (int i = 0; i < n - 1; ++i)
    {
      string str1 = vec[i];
      string str2 = vec[i + 1];
      bool flag = false;
      for (int j = 0; !flag && j < str1.size() && j < str2.size(); ++j)
        if (str1[j] != str2[j])
          {
            flag = true;
            g[str1[j] - 'a'].push_back(str2[j] - 'a');
            in[str2[j] - 'a']++;
          }
      if (!flag && str1.size() > str2.size()) {cout << "Impossible" << endl; return 0;}
    }
  toposort();
  return 0;
}
