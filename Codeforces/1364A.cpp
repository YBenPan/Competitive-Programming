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
      int n, x;
      cin >> n >> x;
      vector<int> a(n);
      int sum = 0;
      int ans;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          sum += a[i];
        }
      if (sum % x != 0) ans = n;
      else
        {
          int f = -1;
          for (int i = 0; i < n; ++i)
            if (a[i] % x != 0) {f = n - i - 1; break;}
          int r = -1;
          for (int i = n - 1; i >= 0; --i)
            if (a[i] % x != 0) {r = i; break;}
          if (f == -1 && r == -1) ans = -1;
          else ans = max(f, r);
          //cout << f << " " << r << endl;
        }
      cout << ans << endl;
    }

  return 0;
}
