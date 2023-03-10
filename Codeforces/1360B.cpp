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
      vector<int> ath(n);
      for (int i = 0; i < n; ++i)
        {
          cin >> ath[i];
        }
      sort(ath.begin(), ath.end());
      int min_diff = 100000000;
      for (int i = 0; i < n - 1; ++i)
        min_diff = min(min_diff, ath[i + 1] - ath[i]);
      cout << min_diff << endl;
    }
  return 0;
}
