#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      long long a, b, c, d;
      long long x, y, x1, y1, x2, y2;
      cin >> a >> b >> c >> d;
      cin >> x >> y >> x1 >> y1 >> x2 >> y2;
      if (a >= b)
        {
          if (x - (a - b) < x1)
            {
              cout << "NO" << endl;
              continue;
            }
          else if (x + 1 > x2 && x - 1 < x1 && a != 0 && b != 0)
            {
              cout << "NO" << endl;
              continue;
            }
        }
      else
        {
          if (x + (b - a) > x2)
            {
              cout << "NO" << endl;
              continue;
            }
          else if (x + 1 > x2 && x - 1 < x1 && a != 0 && b != 0)
            {
              cout << "NO" << endl;
              continue;
            }
        }
      if (c >= d)
        {
          if (y - (c - d) < y1)
            {
              cout << "NO" << endl;
              continue;
            }
          else if (y + 1 > y2 && y - 1 < y1 && c != 0 && d != 0)
            {
              cout << "NO" << endl;
              continue;
            }
        }
      else
        {
          if (y + (d - c) > y2)
            {
              cout << "NO" << endl;
              continue;
            }
          else if (y + 1 > y2 && y - 1 < y1 && c != 0 && d != 0)
            {
              cout << "NO" << endl;
              continue;
            }
        }
      cout << "YES" << endl;
    }
  return 0;
}
