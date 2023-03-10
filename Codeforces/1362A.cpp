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
      LL a, b;
      cin >> a >> b;

      LL div;
      if (a >= b)
        {
          if (a % b != 0)
            {cout << -1 << endl; continue;}
          div = a / b;
        }
      else
        {
          if (b % a != 0) {
            cout << -1 << endl; continue;
          }
          div = b / a;
        }
      LL k = 0;
      while (div > 1 && k >= 0)
        {
          if (div % 2 == 0)
            div /= 2;
          else
            k = -2;
          k++;
        }
      if (k == -1) {cout << -1 << endl; continue;}
      LL tot = 0;
      tot += (k / 3);
      k %= 3;
      tot += (k / 2);
      k %= 2;
      tot += k;
      cout << tot << endl;
    }
  return 0;
}
