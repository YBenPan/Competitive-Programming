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
      int n, m, k;
      cin >> n >> m >> k;
      int cards = n / k;
      if (cards >= m)
        cout << m << endl;
      else
        {
          int x = cards;
          m -= x;
          k--;
          int y;
          if (m % k == 0)
            y = m / k;
          else
            y = m / k + 1;
          cout << x - y << endl;
        }
    }
  return 0;
}
