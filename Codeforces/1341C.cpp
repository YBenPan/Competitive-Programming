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
      vector<int> p(n);
      for (int i = 0; i < n; ++i)
        {
          cin >> p[i];
        }
      bool flag = true;
      for (int i = 1; i < n && flag; ++i)
        {
          if (p[i] - p[i - 1] >= 2)
            flag = false;
        }
      if (flag) cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  return 0;
}
