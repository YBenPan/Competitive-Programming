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
      int odd1 = -1, odd2= -1, even = -1;
      int input;
      for (int i = 1; i <= n; ++i)
        {
          cin >> input;
          if (input % 2 == 1)
            {
              if (odd1 == -1)
                odd1 = i;
              else if (odd2 == -1)
                odd2 = i;
            }
          else
            {
              if (even == -1)
                even = i;
            }
        }
      if (even > 0)
        {
          cout << 1 << endl;
          cout << even << endl;
        }
      else if (odd1 > 0 && odd2 > 0)
        {
          cout << 2 << endl;
          cout << odd1 << " " << odd2 << endl;
        }
      else
        cout << -1 << endl;
    }
  return 0;
}
