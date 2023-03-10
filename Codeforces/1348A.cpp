#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  long long a[40];
  long long tot = 1;
  for (int i = 1; i <= 30; ++i)
    {
      tot *= 2;
      a[i] = tot;
    }
  while (t--)
    {
      int n;
      cin >> n;
      long long sum1 = a[n];
      long long sum2 = 0;
      for (int i = 1; i <= n / 2 - 1; ++i)
        sum1 += a[i];
      for (int i = n / 2; i <= n - 1; ++i)
        sum2 += a[i];
      cout << abs(sum1 - sum2) << endl;
    }
  return 0;
}
