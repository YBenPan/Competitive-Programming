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
      vector<int> a(n);
      for (int i = 0; i < n; ++i)
        cin >> a[i];
      int last = n - 1;
      for (int i = n - 2; i >= 0; --i)
        if (a[i] > a[i + 1]) break;
        else {last--;};
      if (last == 0) {cout << "YES" << endl; continue;}
      int start = 0;
      int maxx_start = a[0];
      for (int i = 1; i < n - 2; ++i)
        {
          if (a[i] < start)
            {
              maxx_start = max(maxx_start, start);
              start = a[i];
            }
        }
      if (maxx_start > a[n - 1])
        {cout << "NO" << endl; continue;}
      else
        {cout << "YES" << endl; continue;}
    }

  return 0;
}
