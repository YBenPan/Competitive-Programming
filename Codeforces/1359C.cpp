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
      long long h, c, t;
      cin >> h >> c >> t;
      if (h == t)
        {
          cout << 1 << endl;
          continue;
        }
      if (h + c >= t * 2)
        {
          cout << 2 << endl;
          continue;
        }
      /*else if (h + c > t * 2)
        {
          double avg_diff = abs(t - (double)(h + c) / 2);
          double min_diff = abs(t - h);
          if (min_diff <= avg_diff)
            cout << 1 << endl;
          else
            cout << 2 << endl;
          continue;
          }*/
      LL denom = 2 * t - h - c;
      LL nom = t - c;
      LL upper = nom / denom + 1;
      LL lower = nom / denom;
      if (nom % denom == 0)
        cout << 2 * lower - 1 << endl;
      else
        {
          LL p = 2 * lower - 1;
          LL q = 2 * upper - 1;
          LL x = h * lower + c * (lower - 1);
          LL y = h * upper + c * (upper - 1);
          LL res1 = x / p;
          LL res2 = y / q;
          LL output = 0;
          if (res1 < t && res2 < t)
            if (y * p <= x * q) output = p;
            else output = q;
          else if (res1 >= t && res2 >= t)
            if (y * p >= x * q) output = p;
            else output = q;
          else if (res1 >= t && res2 < t)
            if (x * q + y * p <= 2 * t * p * q) output = p;
            else output = q;
          else if (res1 < t && res2 >= t)
            if (x * q + y * p >= 2 * t * p * q) output = p;
            else output = q;
          cout << output << endl;
        }
    }

  return 0;
}
