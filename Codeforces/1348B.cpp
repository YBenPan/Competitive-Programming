#include <bits/stdc++.h>
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
      set<int> unique;
      int n, k;
      cin >> n >> k;
      int a[105];
      vector<int> res;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          unique.insert(a[i]);
        }
      if (unique.size() > k)
        {
          cout << -1 << endl;
          continue;
        }
      for (auto i = unique.begin(); i != unique.end(); ++i)
        res.push_back(*i);
      for (int i = res.size(); i < k; ++i)
        res.push_back(1);
      cout << res.size() * n << endl;
      for (int i = 0; i < n; ++i)
        for (auto j = res.begin(); j != res.end(); ++j)
          cout << *j << " ";
      cout << endl;
    }
  return 0;
}
