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
      vector<int> a(n);
      for (int i = 0; i < n; ++i)
        cin >> a[i];
      if (n == 1)
        {
          cout << "YES" << endl;
          continue;
        }
      vector<int> b(n);
      for (int i = 0; i < n; ++i)
        {
          if (i + a[i] < 0)
            b[i] = (n + (i + a[i]) % n) % n;
          else
            b[i] = (i + a[i]) % n;
          //cout << i << " " << b[i] << endl;
        }
      sort(b.begin(), b.end());
      bool flag = true;
      for (int i = 0; i < n - 1 && flag; ++i)
        if (b[i] == b[i + 1])
          flag = false;
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
