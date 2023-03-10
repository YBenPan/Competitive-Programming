#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i)
    cin >> c[i];
  long long dp[100005][2];
  string prev_str, new_str, prev_ori, new_ori;
  cin >> prev_str;
  dp[0][0] = 0;
  dp[0][1] = c[0];
  for (int i = 1; i < n; ++i)
    {
      dp[i][0] = 1e16;
      dp[i][1] = 1e16;
      cin >> new_str;
      new_ori = new_str;
      reverse(new_str.begin(), new_str.end());
      prev_ori = prev_str;
      reverse(prev_str.begin(), prev_str.end());
      if (new_ori >= prev_ori)
        dp[i][0] = dp[i - 1][0];
      if (new_ori >= prev_str)
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
      if (new_str >= prev_ori)
        dp[i][1] =dp[i - 1][0] + c[i];
      if (new_str >= prev_str)
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
      prev_str = new_ori;
    }
  if (dp[n - 1][0] >= 1e16 && dp[n - 1][1] >= 1e16)
    cout << -1 << endl;
  else
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
  return 0;
}
