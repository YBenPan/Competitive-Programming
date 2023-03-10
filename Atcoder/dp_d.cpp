#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL dp[105][100005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, W;
  cin >> N >> W;
  int w[105], v[105];
  memset(dp, 0, sizeof(LL));
  for (int i = 1; i <= N; ++i)
    {
      cin >> w[i] >> v[i];
    }
  //dp[i][j] = max value of items 1 to i with max weight j
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j <= W; ++j)
      {
        if (w[i] > j) dp[i][j] = dp[i - 1][j];
        else dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
      }
  cout << dp[N][W] << endl;
  return 0;
}
