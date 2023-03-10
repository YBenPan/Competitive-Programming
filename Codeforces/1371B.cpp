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
      int n, r;
      cin >> n >> r;
      LL sum;
      int m = min(n, r);
      if (m % 2 == 0) sum = (LL)(m / 2) * (1 + m);
      else sum = (LL)((1 + m) / 2) * m;
      if (n <= r) sum = sum - n + 1;
      cout << sum << endl;
    }

  return 0;
}
