#include <std/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  const int mod = 1000000007;
  int n, k d;
  cin >> n >> k >> d;
  int dp[105][2];
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 1; i <= n; ++i)
    {
      dp[i][0] = 0;
      dp[i][1] = 0;
      for (int j = 1; j <= k && i >= j; ++j)
        if (j < d)
          {
            dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
            dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
          }
        else
          {
            dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
            dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
          }
    }
  cout << dp[n][1] << endl;
  return 0;
}
