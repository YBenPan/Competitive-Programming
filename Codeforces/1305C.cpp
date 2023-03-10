#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n <= m)
    {
      LL ans = 1;
      for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
          ans = ans * (abs(a[i] - a[j]) % m) % m;
      cout << ans << endl;
    }
  else cout << 0 << endl;
  return 0;
}
