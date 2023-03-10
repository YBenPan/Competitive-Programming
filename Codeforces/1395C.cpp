#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int c[205][205];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[205], b[205];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      c[i][j] = a[i] & b[j];
  bool flag1 = true, flag2 = false;
  for (int i = 0; i < (1 << 9); ++i)
    {
      flag1 = true;
      for (int j = 0; j < n && flag1; ++j)
        {
          flag2 = false;
          for (int k = 0; k < m && !flag2; ++k)
            if ((c[j][k] | i) == i)
              flag2 = true;
          if (!flag2) flag1 = false;
        }
      if (flag1) {cout << i << endl; return 0;}
    }
  return 0;
}
