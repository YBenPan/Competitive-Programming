#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, d;
  cin >> n >> d;
  int x, y;
  vector<long long> sum(n + 1);
  for (int i = 0; i < n; ++i)
    {
      cin >> x >> y;
      a.push_back(make_pair(x, y));
    }
  sort(a.begin(), a.end());
  long long maxx = a[0].second;
  sum[0] = 0;
  sum[1] = a[0].second;
  for (int i = 1; i < n; ++i)
    {
      sum[i + 1] = sum[i] + a[i].second;
      int j = 0;
      maxx = max(maxx, (long long)a[i].second);
      while (a[i].first - a[j].first >= d)
        j++;
      maxx = max(maxx, sum[i + 1] - sum[j]);
    }
  cout << maxx << endl;
  return 0;
}
