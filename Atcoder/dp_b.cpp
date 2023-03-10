#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  vector<LL> dp(N);
  dp.assign(N, 100000000000005);
  for (int i = 0; i < N; ++i)
    cin >> a[i];
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  for (int i = 2; i < N; ++i)
    for (int j = max(0, i - K); j < i; ++j)
      dp[i] = min(dp[i], dp[j] + abs(a[j] - a[i]));
  cout << dp[N - 1] << endl;
  return 0;
}
