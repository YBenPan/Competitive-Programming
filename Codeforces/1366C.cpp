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
      int n, m;
      cin >> n >> m;
      short a[35][35];
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; ++j)
          cin >> a[i][j];
      LL tot = 0;
      int cnt[65][2] = {0};
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          cnt[i + j - 2][a[i][j]]++;
      for (int i = 0; i <= n + m - 2; ++i)
        {
          int alt = n + m - 2 - i;
          if (i > alt)
            tot += min(cnt[i][0] + cnt[alt][0], cnt[i][1] + cnt[alt][1]);
        }
      cout << tot << endl;
    }

  return 0;
}
