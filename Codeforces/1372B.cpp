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
      LL n;
      cin >> n;
      if (n % 2 == 0) cout << n / 2 << " " << n / 2 << endl;
      else
        {
          LL max_factor = 1;
          for (int i = 3; i <= sqrt(n); i += 2)
            {
              if (n % i == 0)
                {
                  max_factor = max(max_factor, (LL)i);
                  max_factor = max(max_factor, n / i);
                }
            }
          cout << max_factor << " " << n - max_factor << endl;
        }
    }

  return 0;
}
