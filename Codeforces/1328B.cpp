#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      long long n, k;
      cin >> n >> k;
      long long b1 = 0, b2 = 1;
      for (long long i = 2; i <= 100000; ++i)
        {
          long long num = i * (i - 1) / 2;
          if (num >= k)
            {
              b1 = i;
              b2 = k - (i - 1) * (i - 2) / 2;
              //cout << i << endl;
              break;
            }
        }
      b1 = n - b1;
      b2 = n - b2;
      //cout << b1 << " " << b2 << endl;
      for (int i = 0; i < n; ++i)
        {
          if (i == b1 || i == b2)
            {
              cout << 'b';
            }
          else
            {
              cout << 'a';
            }
        }
      cout << endl;
    }
  return 0;
}
