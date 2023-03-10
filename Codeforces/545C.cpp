#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int x, y;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i)
    {
      cin >> x >> y;
      a.push_back(make_pair(x, y));
    }
  sort(a.begin(), a.end());
  if (n == 1)
    {
      cout << 1 << endl;
      return 0;
    }
  int tot = 2;
  for (int i = 1; i < n - 1; ++i)
    {
      if (a[i].first - a[i].second > a[i - 1].first)
        tot++;
      else if (a[i].first + a[i].second < a[i + 1].first)
        {
          tot++;
          a[i].first += a[i].second;
        }
    }
  cout << tot << endl;
  return 0;
}
