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
      int ans; // Ash: 0. FF: 1
      if (n == 1) ans = 1;
      else if (n == 2) ans = 0;
      else if (n % 2 == 1) ans = 0;
      else
        {
          int cnt = 0;
          while (n % 2 == 0)
            {
              n /= 2;
              cnt++;
            }
          bool flag = true;
          if (n == 1) ans = 1;
          else
            {
              for (int i = 3; i <= sqrt(n) && flag; ++i)
                if (n % i == 0) flag = false;
              if (flag && cnt == 1) ans = 1;
              else ans = 0;
            }
        }
      if (ans == 0) cout << "Ashishgup" << endl;
      else cout << "FastestFinger" << endl;
    }
  return 0;
}
