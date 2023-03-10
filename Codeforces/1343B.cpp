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
      if (n % 4 != 0)
        {
          cout << "NO" << endl;
          continue;
        }
      cout << "YES" << endl;
      long long sum1 = 0;
      long long sum2 = 0;
      for (int i = 1; i <= n / 2; ++i)
        {
          cout << i * 2 << " ";
          sum1 += (i * 2);
        }
      for (int i = 1; i <= n / 2 - 1; ++i)
        {
          cout << i * 2 - 1 << " ";
          sum2 += (i * 2 - 1);
        }
      cout << sum1 - sum2 << endl;
    }
  return 0;
}
