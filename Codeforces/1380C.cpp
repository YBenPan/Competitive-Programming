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
      int n, x;
      cin >> n >> x;
      vector<int> a(n);
      for (int i = 0; i < n; ++i) cin >> a[i];
      sort(a.begin(), a.end(), greater<int>());
      int tot = 0;
      int length = 0;
      for (int i = 0; i < n; ++i)
        {
          length++;
          if (length * a[i] >= x)
            {
              tot++;
              length = 0;
            }
        }
      cout << tot << endl;
    }

  return 0;
}
