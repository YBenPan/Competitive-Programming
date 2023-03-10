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
      long long x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if (x1 == x2 || y1 == y2)
        {
          cout << 1 << endl;
          continue;
        }
      long long diffX = x2 - x1;
      long long diffY = y2 - y1;
      long long continued = abs(diffX - diffY) - 1;
      long long sum = 0;
      long long first = min(diffX, diffY);
      long long second = max(diffX, diffY);
      if (first == 1)
        {
          cout << second + 1 << endl;
          continue;
        }
      sum += (first + 1) * first;
        sum += (continued * first);
        cout << sum + 1 << endl;
    }
  return 0;
}
