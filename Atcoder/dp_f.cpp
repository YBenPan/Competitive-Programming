#include <bits/stdc++.h>
#define LL long long
using namespace std;
int dp[3005][3005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, 0, sizeof(dp));
  string s, t;
  cin >> s;
  cin >> t;
  for (int i = 0; i <= s.size(); ++i)
    for (int j = 0; j <= t.size(); ++j)
      {
        if (i == 0 || j == 0) dp[i][j] = 0;
        else if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
  int a = s.size(), b = t.size();
  string ans;
  while (a && b)
    {
      if (s[a - 1] == t[b - 1])
        {
          ans.push_back(s[a - 1]);
          a--; b--;
        }
      else if (dp[a - 1][b] > dp[a][b - 1])
        a--;
      else b--;
    }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
