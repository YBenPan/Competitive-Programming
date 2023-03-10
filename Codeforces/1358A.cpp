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
      int n, m;
      cin >> n >> m;
      if (n * m % 2 == 1)
        cout << (n * m) / 2 + 1 << endl;
      else
        cout << (n * m) / 2 << endl;
    }

  return 0;
}
