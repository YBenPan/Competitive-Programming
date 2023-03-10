#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<int> letter;
vector<int> factor;
bool check(int x, int y)
{
  int tot = 0;
  if (x == 0) return true;
  for (int i : letter)
    tot += (i / x);
  return tot >= y;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n, k;
      cin >> n >> k;
      string str;
      cin >> str;
      int cnt[26] = {0};
      for (int i = 0; i < str.size(); ++i)
        cnt[str[i] - 'a']++;
      letter.clear();
      for (int i = 0; i < 26; ++i)
        if (cnt[i] > 0) letter.push_back(cnt[i]);
      sort(letter.begin(), letter.end());
      factor.clear();
      for (int i = 1; i <= k; ++i)
        if (k % i == 0) factor.push_back(i);
      int ans = 0;
      for (int i = 0; i < factor.size(); ++i)
        {
          int l = 0;
          int r = n;
          int res = 0;
          while (l <= r)
            {
              int mid = (l + r) / 2;
              if (check(mid, factor[i]))
                {
                  res = mid;
                  l = mid + 1;
                }
              else
                r = mid - 1;
            }
          ans = max(ans, res * factor[i]);
        }
      cout << ans << endl;
    }

  return 0;
}
