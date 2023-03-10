#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
double dp[3005][3005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  double p[3005];
  for (int i = 1; i <= N; ++i) cin >> p[i];
  memset(dp, 0, sizeof(dp));
  dp[1][0] = p[1];
  dp[0][1] = 1 - p[1];
  for (int i = 2; i <= N; ++i)
    {
      dp[i][0] = dp[i - 1][0] * p[i];
      dp[0][i] = dp[0][i - 1] * (1 - p[i]);
      for (int j = 1; j < i; ++j)
        dp[j][i - j] = dp[j - 1][i - j] * p[i] + dp[j][i - j - 1] * (1 - p[i]);
    }
  double sum = 0;
  for (int i = 0; i <= N; ++i)
    if (i > N - i) sum += dp[i][N - i];
  cout << setprecision(10) << sum << endl;
  return 0;
}
