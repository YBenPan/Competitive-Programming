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
      int cnt = 0, prefix_cnt = 0, suffix_cnt = 0;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          if (a[i] == i + 1) cnt++;
        }
      int in = 0;
      while (a[in] == in + 1) {prefix_cnt++; in++;}
      in = n - 1;
      while (a[in] == in + 1) {suffix_cnt++; in--;}
      if (cnt == n) cout << 0 << endl;
      else if (cnt == prefix_cnt || cnt == suffix_cnt || cnt == prefix_cnt + suffix_cnt)  cout << 1 << endl;
      else cout << 2 << endl;
    }

  return 0;
}
