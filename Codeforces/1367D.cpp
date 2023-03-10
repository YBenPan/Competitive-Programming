#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      string str;
      cin >> str;
      int m;
      cin >> m;
      vector<int> b(m);
      vector< vector<int> > groups;
      for (int i = 0; i < m; ++i)
        {
          cin >> b[i];
        }
      while (true)
        {
          vector<int> pos;
          for (int i = 0; i < m; ++i)
            if (b[i] == 0)
              pos.push_back(i);
          if (pos.empty()) break;
          groups.push_back(pos);
          for (int i = 0; i < m; ++i)
            {
              if (b[i] == 0) b[i] = INT_MAX;
              else for (int j : pos)
                     b[i] -= abs(i - j);
            }
        }
      map<char, int> cnt;
      for (int i = 0; i < str.size(); ++i)
        cnt[str[i]]++;
      auto j = cnt.rbegin();
      string ans(m, '0');
      for (auto i : groups)
        {
          while (j -> second < i.size()) j++;
          for (int k : i) ans[k] = j -> first;
          j++;
        }
      cout << ans << endl;
    }

  return 0;
}
