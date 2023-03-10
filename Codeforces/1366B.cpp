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
      int n, m, x;
      cin >> n >> x >> m;
      int lower = x, upper = x;
      for (int i = 0; i < m; ++i)
        {
          int l, r;
          cin >> l >> r;
          if (r >= lower && l <= upper)
            {
              lower = min(l, lower);
              upper = max(r, upper);
            }
        }
      cout << upper - lower + 1 << endl;
    }

  return 0;
}
