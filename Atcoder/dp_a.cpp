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
  vector<int> a(N);
  vector<int> dp(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  for (int i = 2; i < N; ++i)
    dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 2]), dp[i - 1] + abs(a[i] - a[i - 1]));
  cout << dp[N - 1] << endl;
  return 0;
}
