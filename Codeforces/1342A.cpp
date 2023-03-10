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
      long long x, y;
      long long a, b;
      cin >> x >> y;
      cin >> a >> b;
      if (x == 0 && y == 0)
        {
          cout << 0 << endl;
          continue;
        }
      long long option1 = 0; // both
      long long min_abs = min(x, y);
      option1 = min_abs * b + (x - min_abs) * a + (y - min_abs) * a;
      long long option2 = 0;
      option2 = (x + y) * a;
      cout << min(option1, option2) << endl;
    }
  return 0;
}
