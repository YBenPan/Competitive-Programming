#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<int, int> num;
  int input;
  int maxx = 0;
  for (int i = 0; i < n; ++i)
    {
      cin >> input;
      num[input]++;
      maxx = max(maxx, input);
    }
  long long dp[100005];
  /*vector<int> corr;
  for (int i = 1; i <= 100000; ++i)
    if (num[i] > 0)
      {
        corr.push_back(i);
      }
  for (auto i : corr)
    cout << i << " ";*/
  dp[0] = 0;
  dp[1] = num[1];
  for (int i = 2; i <= maxx; ++i)
    {
      dp[i] = max(dp[i - 2] + (long long)num[i] * i, dp[i - 1]);
    }
  cout << dp[maxx] << endl;
  return 0;
}
