#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int dp[205][205][205] = {0};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int rr, gg, bb;
  cin >> rr >> gg >> bb;
  int r[205], g[205], b[205];
  for (int i = 0; i < rr; ++i) cin >> r[i];
  for (int i = 0; i < gg; ++i) cin >> g[i];
  for (int i = 0; i < bb; ++i) cin >> b[i];
  sort(r, r + rr, greater<int>());
  sort(g, g + gg, greater<int>());
  sort(b, b + bb, greater<int>());
  int ans = 0;
  for (int i = 0; i <= rr; ++i)
    for (int j = 0; j <= gg; ++j)
      for (int k = 0; k <= bb; ++k)
        {
          if (i < rr && j < gg)
            dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
          if (i < rr && k < bb)
            dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
          if (j < gg && k < bb)
            dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
          ans = max(ans, dp[i][j][k]);
        }
  cout << ans << endl;
  return 0;
}
