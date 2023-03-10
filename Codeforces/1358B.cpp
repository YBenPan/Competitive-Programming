#include <bits/stdc++.h>
#include <vector>
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
        {
          cin >> a[i];
        }
      sort(a.begin(), a.end());
      int cnt = n - 1;
      while (cnt >= 0)
        {
          if (a[cnt] > cnt + 1)
            cnt--;
          else
            break;
        }
      cout << cnt + 2 << endl;
    }

  return 0;
}
