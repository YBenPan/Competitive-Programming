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
  if (n == 1)
    {
      cout << 1 << endl;
      return 0;
    }
  sort(a.begin(), a.end());
  vector<int> Left(n), Right(n);
  Left[0] = 1;
  if (a[0].first + a[0].second < a[1].first)
    Right[0] = 1;
  else
    Right[0] = 0;
  for (int i = 1; i < n; ++i)
    {
      Left[i] = max(Left[i - 1], Right[i - 1]);
      Right[i] = max(Left[i - 1], Right[i - 1]);
      if (i == n - 1 || a[i].first + a[i].second < a[i + 1].first)
        {
          Right[i] = max(Right[i], Left[i - 1] + 1);
          Right[i] = max(Right[i], Right[i - 1] + 1);
        }
      if (a[i].first - a[i].second > a[i - 1].first)
        Left[i] = max(Left[i], Left[i - 1] + 1);
      if (a[i].first - a[i].second > a[i - 1].first + a[i - 1].second)
        Left[i] = max(Left[i], Right[i - 1] + 1);
      //cout << i << " " << Left[i] << " " << Right[i] << endl;
    }
  cout << max(Left[n - 1], Right[n - 1]) << endl;
  return 0;
}
