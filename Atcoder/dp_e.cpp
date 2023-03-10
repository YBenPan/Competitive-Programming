#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL dp[105][100005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, C;
  cin >> N >> C;
  int w[105], v[105];
  memset(dp, 0x7f, sizeof(dp));
  for (int i = 1; i <= N; ++i) cin >> w[i] >> v[i];
  int ans = 0;
  dp[0][0] = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = 100000; j >= 0; --j)
      {
        if (v[i] > j) dp[i][j] = dp[i - 1][j];
        else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        if (dp[i][j] <= C) ans = max(ans, j);
        }
  cout << ans << endl;
  return 0;
}
