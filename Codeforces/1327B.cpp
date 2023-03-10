#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      bool taken_m[100005] = {false};
      bool taken_f[100005] = {false};
      int k;
      for (int i = 1; i <= n; ++i)
        {
          cin >> k;
          int input;
          bool flag = false;
          for (int j = 1; j <= k; ++j)
            {
              cin >> input;
              if (!taken_m[input] && !flag)
                {
                  taken_m[input] = true;
                  taken_f[i] = true;
                  flag = true;
                }
            }
        }
      int M = -1, F = -1;
      for (int i = 1; i <= n && ((M < 0) || (F < 0)); ++i)
        {
          if (!taken_m[i])
            {
              M = i;
            }
          if (!taken_f[i])
            {
              F = i;
            }
        }
      if (M < 0 && F < 0)
        {
          cout << "OPTIMAL" << endl;
        }
      else
        {
          cout << "IMPROVE" << endl;
          cout << F << " " << M << endl;
        }
    }
  return 0;
}
