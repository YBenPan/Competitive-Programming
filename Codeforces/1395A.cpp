#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
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
      int c[4];
      cin >> c[0] >> c[1] >> c[2] >> c[3];
      int cnt_odd = 0;
      bool flag = false;
      for (int i = 0; i < 4; ++i)
        if (c[i] % 2 == 1) cnt_odd++;
      if (cnt_odd <= 1) flag = true;
      if (c[0] > 0 && c[1] > 0 && c[2] > 0)
        {
          for (int i = 0; i < 3; ++i) c[i]--;
          c[3] += 3;
          cnt_odd = 0;
          for (int i = 0; i < 4; ++i)
            if (c[i] % 2 == 1) cnt_odd++;
          if (cnt_odd <= 1) flag = true;
        }
      if (flag) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

  return 0;
}
