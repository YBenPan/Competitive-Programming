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
      int n;
      cin >> n;
      if (n == 1) {cout << 0 << endl; continue;}
      int cnt2 = 0, cnt3 = 0;
      while (n % 2 == 0)
        {
          cnt2++;
          n /= 2;
        }
      while (n % 3 == 0)
        {
          cnt3++;
          n /= 3;
        }
      if (n != 1 || cnt2 > cnt3 || cnt3 == 0) {cout << -1 << endl; continue;}
      else cout << cnt3 - cnt2 + cnt3 << endl;
    }

  return 0;
}
