#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n, k;
      cin >> n >> k;
      vector<vector<int>> equal(k);
      int limit = k / 2;
      if (k % 2 == 1)
        {
          limit++;
        }
      for (int i = 0; i < limit; ++i)
        {
          int num = i;
          while (num < n)
            {
              equal[i].push_back(num);
              num += k;
            }
          if (k % 2 == 1 && i == k / 2)
            {
              continue;
            }
          num = n - i - 1;
          while (num >= 0)
            {
              equal[i].push_back(num);
              num -= k;
            }
        }
      string str;
      cin >> str;
      long long tot = 0;
      for (int i = 0; i < limit; ++i)
        {
          int common = 0;
          int cnt[27] = {0};
          for (int j = 0; j < (int)equal[i].size(); ++j)
            {
              cnt[str[equal[i][j]] - 97]++;
            }
          for (int j = 0; j < 26; ++j)
            {
              common = max(common, cnt[j]);
            }
          tot += (equal[i].size() - common);
        }
      cout << tot << endl;
    }
}
