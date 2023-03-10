#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  long long sum[5000];
  for (int i = 1; i <= 3163; ++i)
    {
      sum[i] = i * i;
    }
  while (t--)
    {
      int n, k;
      cin >> n >> k;
      if (n % 2 == 0 && k % 2 == 1)
        {
          cout << "NO" << endl;
        }
      else if (k > 3163)
        {
          cout << "NO" << endl;
        }
      else if (k > n)
        {
          cout << "NO" << endl;
        }
      else if (n % 2 == 1 && k % 2 == 0)
        {
          cout << "NO" << endl;
        }
      else if (n < sum[k])
        {
          cout << "NO" << endl;
        }
      else
        {
          cout << "YES" << endl;
        }
    }
  return 0;
}
