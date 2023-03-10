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
      int n;
      cin >> n;
      vector<int> a(n);
      int cnt_odd = 0;
      int cnt_even = 0;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          if (i % 2 == 0 && a[i] % 2 == 1) cnt_odd++;
          else if (i % 2 == 1 && a[i] % 2 == 0) cnt_even++;
        }
      if (cnt_odd == cnt_even) cout << cnt_odd << endl;
      else cout << -1 << endl;
    }
  return 0;
}
