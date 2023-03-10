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
      LL l, r, m;
      cin >> l >> r >> m;
      LL diff = r - l;
      if (m < l)
        {
          cout << l << " " << l << " " << l - m + l << endl;
          continue;
        }
      for (LL i = l; i <= r; ++i)
        {
          LL a = m / i * i;
          LL b = a + i;
          if (m - a <= diff)
            {
              cout << i << " " << l + m - a<< " " << l << endl;
              break;
            }
          else if (b - m <= diff)
            {
              cout << i << " " << l << " " << l + b - m << endl;
              break;
            }
        }
    }

  return 0;
}
