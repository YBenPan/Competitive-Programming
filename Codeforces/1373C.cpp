#include <bits/stdc++.h>
#define LL long long
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
      string str;
      cin >> str;
      int n = str.size();
      int f[1000005], cnt[1000005];
      int cur = 0;
      int minn = 1000005;
      for (int i = 0; i < n; ++i)
        {
          if (str[i] == '+') cur++;
          else cur--;
          f[i] = cur;
          minn = min(minn, cur);
          cnt[i] = -1;
        }
      if (minn > 0) {cout << n << endl; continue;}
      minn = abs(minn);
      cnt[minn] = n;
      for (int i = 0; i < n; ++i)
        {
          cur = abs(f[i]);
          if (f[i] < 0 && cnt[cur - 1] == -1) cnt[cur - 1] = i + 1;
          if (f[i] == -1 * minn) {break;}
        }
      LL tot = 0;
      for (int i = 0; i <= minn; ++i)
        {
          tot += cnt[i];
        }
      cout << tot << endl;
    }

  return 0;
}
