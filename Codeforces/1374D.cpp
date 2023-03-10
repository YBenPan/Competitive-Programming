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
      int n, k;
      cin >> n >> k;
      int input;
      map<int, int> cnt;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          input = k - input % k;
          if (input % k) cnt[input]++;
        }
      int maxx = 0;
      int maxx_num;
      for (map<int, int>::iterator i = cnt.begin(); i != cnt.end(); ++i)
        {
          if (i->second >= maxx)
            {
              maxx = i->second;
              maxx_num = i->first;
            }
        }
      if (maxx == 0) cout << 0 << endl;
      else cout << k * (LL)(maxx - 1) + maxx_num + 1 << endl;
    }

  return 0;
}
