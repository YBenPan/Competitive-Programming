#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      bool cnt[8005] = {false};
      int sum[8005];
      sum[0] = 0;
      int x;
      for (int i = 1; i <= n; ++i)
        {
          cin >> x;
          sum[i] = sum[i - 1] + x;
        }
      for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i - 1; ++j)
          if (sum[i] - sum[j] <= n)
            cnt[sum[i] - sum[j]] = true;
      long long tot = 0;
      for (int i = 1; i <= n; ++i)
        {
          int cur = sum[i] - sum[i - 1];
          if (cur <= n && cnt[cur])
            tot++;
        }
      cout << tot << endl;
    }
  return 0;
}
