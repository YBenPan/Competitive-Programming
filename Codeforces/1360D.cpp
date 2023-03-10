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
      long long n, k;
      cin >> n >> k;
      if (k >= n)
        {
          cout << 1 << endl;
          continue;
        }
      long long minn = n;
      for (long long i = 2; i <= sqrt(n); ++i)
        {
          if (i <= k && n % i == 0)
            minn = min(minn, n / i);
          if (n <= i * k && n % i == 0)
            minn = min(minn, i);
        }
      cout << minn << endl;
    }
  return 0;
}
