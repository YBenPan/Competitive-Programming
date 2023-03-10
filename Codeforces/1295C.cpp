#include <bits/stdc++.h>
#define LL long long
using namespace std;
int dp[100005][26];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      string s, t;
      cin >> s;
      int n = s.size();
      cin >> t;
      memset(dp, -1, sizeof(dp));
      dp[n - 1][s[n - 1] - 'a'] = n - 1;
      for (int i = n - 2; i >= 0; --i)
        {
          for (int j = 0; j < 26; ++j)
            dp[i][j] = dp[i + 1][j];
          dp[i][s[i] - 'a'] = i;
        }
      int pos = 0;
      int ans = 1;
      for (int i = 0; i < t.size(); ++i)
        {
          int cur = t[i] - 'a';
          if (dp[0][cur] == -1)
            {
              ans = -1;
              break;
            }
          if (pos == s.size() || dp[pos][cur] == -1)
            {
              ans++;
              pos = 0;
            }
          pos = dp[pos][cur] + 1;
        }
      cout << ans << endl;
    }

  return 0;
}
