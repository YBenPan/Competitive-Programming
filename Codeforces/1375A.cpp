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
      int n;
      cin >> n;
      int a[105];
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          if (i % 2 == 0)
            {
              if (a[i] < 0) cout << -1 * a[i] << " ";
              else cout << a[i] << " ";
            }
          else
            {
              if (a[i] > 0) cout << -1 * a[i] << " ";
              else cout << a[i] << " ";
            }
        }
      cout << endl;
    }

  return 0;
}
