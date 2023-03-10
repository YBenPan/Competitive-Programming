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
      LL a, b, n, m;
      cin >> a >> b >> n >> m;
      LL minn = min(a, b);
      bool flag = true;
      if (m > minn) flag = false;
      else if (a + b < n + m) flag = false;
      if (flag) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

  return 0;
}
