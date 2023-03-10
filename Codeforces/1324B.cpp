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
      int a[5005];
      a[0] = -1;
      a[5001] = -1;
      int cnt[5005] = {0};
      for (int i = 1; i <= n; ++i)
        {
          cin >> a[i];
          cnt[a[i]]++;
        }
      bool flag = false;
      for (int i = 1; i <= n && !flag; ++i)
        {
          if (cnt[a[i]] >= 2)
            {
              flag = true;
              if (cnt[a[i]] == 2 && (a[i - 1] == a[i] || a[i + 1] == a[i]))
                  flag = false;
            }
        }
      if (flag)
        cout << "YES" << endl;
      if (!flag)
        cout << "NO" << endl;
    }
}
