#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> c[i];
  int dp[3][100005];
  memset(dp, 0, sizeof(int));
  dp[0][0] = a[0];
  dp[1][0] = b[0];
  dp[2][0] = c[0];
  for (int i = 1; i < N; ++i)
    {
      dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
      dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
      dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    }
  cout << max(max(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]) << endl;
  return 0;
}
