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
      int x, y, n;
      cin >> x >> y >> n;
      int md = n % x;
      if (md == y) {cout << n << endl; continue;}
      if (md < y) n -= (md + (x - y));
      else n -= (md - y);
      cout << n << endl;
    }

  return 0;
}
