#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  const int MOD = 1000000007;
  int n, length;
  cin >> n >> length;
  int tot = 0;
  for (int i = 1; i <= n; ++i)
    {
      dp[1][i] = 1;
    }
  for (int i = 2; i <= length; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = j; k <= n; k += j)
        dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD;
  for (int i = 1; i <= n; ++i)
    tot = (tot + dp[length][i]) % MOD;
    cout << tot << endl;
  return 0;
}
