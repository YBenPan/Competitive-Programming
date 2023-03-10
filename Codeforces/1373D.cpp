#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n;
vector<int> a(n);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      cin >> n;
      a.resize(n);
      a.clear();
      LL maxx = 0, even_sum = 0, change_odd = 0, change_even = 0;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          if (i % 2 == 0)
            {
              even_sum += a[i];
            }
        }
      for (int i = 0; i < n - 1; i += 2)
        {
          change_even += (a[i + 1] -a[i]);
          if (change_even < 0) change_even = 0;
          maxx = max(maxx, change_even);
        }
      for (int i = 1; i < n - 1; i += 2)
        {
          change_odd += (a[i] - a[i + 1]);
          if (change_odd < 0) change_odd = 0;
          maxx = max(maxx, change_odd);
        }
      cout << even_sum + maxx << endl;
    }
  return 0;
}
