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
      long long input;
      vector<int> a;
      long long maxx = -1000000000;
      long long maxx_diff = 0;
      for (int i = 0 ; i < n; ++i)
        {
          cin >> input;
          a.push_back(input);
          maxx = max(input, maxx);
          if (input < maxx)
            maxx_diff = max(maxx_diff, maxx - input);
        }
      if (maxx_diff == 0)
        {
          cout << 0 << endl;
          continue;
        }
      double sec = log(maxx_diff) / log(2);
      int res = ceil(sec);
      if (maxx_diff == pow(2, res))
        res++;
      cout << res << endl;
    }
  return 0;
}
