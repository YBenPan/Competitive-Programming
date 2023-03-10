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
      int n;
      bool odd = false;
      bool even = false;
      int input;
      cin >> n;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          if (!odd && input % 2 == 1)
            odd = true;
          if (!even && input % 2 == 0)
            even = true;
        }
      if (odd & even)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  return 0;
}
