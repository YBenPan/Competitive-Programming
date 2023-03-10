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
      LL a, b, n;
      cin >> a >> b >> n;
      int i = 0;
      while (true)
        {
          ++i;
          if (a > b)
            b += a;
          else
            a += b;
          if (a > n || b > n) break;
        }
      cout << i << endl;
    }

  return 0;
}
