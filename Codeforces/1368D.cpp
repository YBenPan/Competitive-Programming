#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int bits[25] = {0};
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= 20; ++j)
      {
        bits[j] += (a[i] & 1);
        a[i] = a[i] >> 1;
      }
  LL ans = 0;
  for (int i = 0; i < n; ++i)
    {
      int x = 0;
      for (int j = 0; j <= 20; ++j)
        if (bits[j])
          {
            bits[j]--;
            x += (1 << j);
          }
      ans += (LL)x * x;
    }
  cout << ans << endl;
  return 0;
}
