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
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; ++i)
        cin >> a[i];
      int minn = 1000000005;
      int maxx = 0;
      for (int i = 0; i < n; ++i)
        {
          if (i != n - 1 && a[i] != -1 && a[i + 1] == -1)
            {
              minn = min(minn, a[i]);
              maxx = max(maxx, a[i]);
            }
          if (i != 0 && a[i] != -1 && a[i - 1] == -1)
            {
              minn = min(minn, a[i]);
              maxx = max(maxx, a[i]);
            }
        }
      int m = (minn + maxx) / 2;
      int tot = 0;
      if (a[0] == -1)
        a[0] = m;
      for (int i = 0; i < n - 1; ++i)
        {
          if (a[i + 1] == -1)
            a[i + 1] = m;
          tot = max(tot, abs(a[i + 1] - a[i]));
        }
      cout << tot << " " << m << endl;
    }

  return 0;
}
