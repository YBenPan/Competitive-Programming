#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
    {
      int n;
      cin >> n;
      vector<long long> a, b;
      long long x, y;
      cin >> x >> y;
      a.push_back(x);
      b.push_back(y);
      cin >> x >> y;
      a.push_back(x);
      b.push_back(y);
      long long min_bullets = a[1] - max((long long)0, a[1] - b[0]);
      long long min_index = 1;
      for (int i = 2; i < n; ++i)
        {
          cin >> x >> y;
          a.push_back(x);
          b.push_back(y);
          long long diff = a[i] - max((long long)0, a[i] - b[i - 1]);
          if (diff < min_bullets)
            {
              min_bullets = diff;
              min_index = i;
            }
        }
      long long diff = a[0] - max((long long)0, a[0] - b[n - 1]);
      if (diff < min_bullets)
        {
          min_bullets = diff;
          min_index = 0;
        }
      //cout << min_index << " " << min_bullets << endl;
      long long tot = a[min_index];
      int i = min_index;
      int j = i + 1;
      if (j >= n)
        j = 0;
      while (j != min_index)
        {
          tot += max((long long)0, (a[j] - b[i]));
          ++j;
          ++i;
          if (j >= n)
            j = 0;
          if (i >= n)
            i = 0;
        }
      cout << tot << endl;
    }
  return 0;
}
