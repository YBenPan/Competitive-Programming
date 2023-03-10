#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int h, c, t;
  cin >> h >> c >> t;
  double tot = 0;
  for (int i = 1; i <= 10000; ++i)
    {
      tot += h;
      cout << i << " " << i - 1 << " " << tot / (i * 2 - 1) << endl;
      tot += c;
      cout << i << " " << i << " " << tot / (i * 2) << endl;
    }
  return 0;
}
