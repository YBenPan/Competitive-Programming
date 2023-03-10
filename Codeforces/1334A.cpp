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
      cin >> n;
      int p, c;
      int last_p, last_c;
      cin >> p >> c;
      last_p = p;
      last_c = c;
      bool flag = true;
      if (p < c)
        flag = false;
      for (int i = 1; i < n; ++i)
        {
          cin >> p >> c;
          if (p - last_p < c - last_c)
            flag = false;
          else if (p < last_p || c < last_c)
            flag = false;
          last_p = p;
          last_c = c;
        }
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
