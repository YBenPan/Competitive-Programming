#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
char g[1005][1005];
int dp[1005][1005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int H, W;
  cin >> H >> W;
  char ch;
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      {
        cin >> g[i][j];
      }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      {
        if (i == 0 && j == 0) continue;
        if (g[i][j] == '#') continue;
        if (i != 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        if (j != 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      }
  cout << dp[H - 1][W - 1] % MOD << endl;
  return 0;
}
