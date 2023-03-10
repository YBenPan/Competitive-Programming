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
      int n, k;
      cin >> n >> k;
      vector<int> a(n + 5);
      for (int i = 0; i < n; ++i)
        cin >> a[i];
      vector<int> cnt(n + 5);
      cnt[0] = 0;
      for (int i = 1; i < n - 1; ++i)
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
          cnt[i] = cnt[i - 1] + 1;
        else
          cnt[i] = cnt[i - 1];
      cnt[n - 1] = cnt[n - 2];
      int maxx = 0;
      int maxx_index = 0;
      for (int i = 0; i <= n - k; ++i)
        {
          int j = i + k - 1;
          //cout << i << " " << j << " " << cnt[j - 1] - cnt[i] << endl;
          if (cnt[j - 1] - cnt[i] > maxx)
            {
              maxx = cnt[j - 1] - cnt[i];
              maxx_index = i;
            }
        }
      cout << maxx + 1 << " " << maxx_index + 1 << endl;
    }
  return 0;
}
