#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool cmp(const pair<int, int> & a, const pair<int, int> &b)
{
  if (a.second != b.second)
    return a.first < b.first;
  else
    return false;
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
      int n;
      cin >> n;
      vector<pair<int, int>> a;
      int x[505], y[505];
      for (int i = 0; i < n; ++i)
        cin >> x[i];
      for (int i = 0; i < n; ++i)
        {
          cin >> y[i];
          a.push_back({x[i], y[i]});
        }
      sort(a.begin(), a.end(), cmp);
      for (int i = 0; i < n; ++i)
      cout << a[i].first << " " << a[i].second << endl;
      bool flag = true;
      for (int i = 0; i < n - 1 && flag; ++i)
        if (a[i].first > a[i + 1].first)
          {
            cout << "No" << endl;
            flag = false;
          }
      if (flag) cout << "Yes" << endl;
    }

  return 0;
}
