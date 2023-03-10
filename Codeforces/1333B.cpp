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
      bool neg[100005] = {false};
      bool pos[100005] = {false};
      int n;
      cin >> n;
      int a[100005];
      int b;
      bool flag_neg = false;
      bool flag_pos = false;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          if (a[i] == -1 && !flag_neg)
            {
              flag_neg = true;
              for (int j = i + 1; j < n; ++j)
                neg[j] = true;
            }
          if (a[i] == 1 && !flag_pos)
            {
              flag_pos = true;
              for (int j = i + 1; j < n; ++j)
                pos[j] = true;
            }
        }
      bool flag = true;
      for (int i = 0; i < n; ++i)
        {
          cin >> b;
          int diff = b - a[i];
          if (diff > 0 && !pos[i])
            flag = false;
          if (diff < 0 && !neg[i])
            flag = false;
        }
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
