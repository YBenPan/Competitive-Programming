#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
    {
      long long n, k;
      cin >> n >> k;
      if (n % 2 == 0)
        cout << n + 2 * k << endl;
      else
        {
          long long div = n;
          for (int i = 3; i <= n; ++i)
            if (n % i == 0)
              {
                div = i;
                break;
              }
          cout << n + div + (k - 1) * 2 << endl;
        }
    }
  return 0;
}
