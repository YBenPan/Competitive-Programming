#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  int x, y;
  for (int i = 0; i < n; ++i)
    {
      cin >> x >> y;
      a.push_back(make_pair(x, y));
    }
  sort(a.begin(), a.end());
  int max_date = -1;
  for (int i = 0;i < n; ++i)
    {
      if (a[i].second >= max_date)
        {
          max_date = max(max_date, a[i].second);
        }
      else
        {
          max_date = max(max_date, a[i].first);
        }
    }
  cout << max_date << endl;
  return 0;
}
