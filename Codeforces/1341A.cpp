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
      int n, a, b, c, d;
      cin >> n >> a >> b >> c >> d;
      long long lower_bound = (a - b) * n;
      long long upper_bound = (a + b) * n;
      if (lower_bound > c - d && lower_bound > c + d || upper_bound < c - d && upper_bound < c + d)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
  return 0;
}
