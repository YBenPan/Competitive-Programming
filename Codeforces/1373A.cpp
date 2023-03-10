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
      LL a, b, c;
      cin >> a >> b >> c;
      if (a < c)
        cout << 1 << " ";
      else cout << -1 << " ";
      if (c < (LL)a * b)
        cout << b << endl;
      else
        cout << -1 << endl;
    }

  return 0;
}
