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
      long long i = 4;
      while (i - 1 <= n)
        {
          if (n % (i - 1) == 0)
            {
              cout << n / (i - 1) << endl;
              break;
            }
          i *= 2;
        }
    }
  return 0;
}
