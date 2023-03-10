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
      int a[505];
      int b[505];
      for (int i = 0; i < n; ++i) cin >> a[i];
      cin >> b[0];
      int start = b[0];
      bool flag = false;
      for (int i = 1; i < n; ++i)
        {
          cin >> b[i];
          if (b[i] != start)
            flag = true;
        }
      bool order = true;
      for (int i = 0; i < n - 1 && order; ++i)
        {
          if (a[i] > a[i +  1])
            order = false;
        }
      if (!flag && order) flag = true;
      if (flag)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }

  return 0;
}
