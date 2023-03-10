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
      int a, b;
      cin >> a >> b;
      if (a < b)
        {
          int tmp = a;
          a = b;
          b = tmp;
        }
      if (a >= b * 2) {cout << b << endl; continue;}
      int ans = a - b;
      a -= ans * 2;
      b -= ans;
      ans += (a / 3) * 2;
      a %= 3;
      b %= 3;
      if (a == 2) ans++;
      cout << ans << endl;
    }

  return 0;
}
