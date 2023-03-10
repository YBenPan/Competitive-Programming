#include <bits/stdc++.h>
using namespace std;
int check_sign(int x)
{
  if (x > 0)
    return 1;
  else
    return -1;
}
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
      vector<int> a;
      int input;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          a.push_back(input);
        }
      int sign = check_sign(a[0]);
      int max_interval = a[0];
      int i = 1;
      long long sum = 0;
      if (n == 1)
        {
          cout << a[0] << endl;
          continue;
        }
      while (i < n)
        {
          while (check_sign(a[i]) == sign && i < n)
            {
              max_interval = max(max_interval, a[i]);
              i++;
            }
          sign = -sign;
          sum += max_interval;
          max_interval = -1000000000;
        }
      cout << sum << endl;
    }
  return 0;
}
