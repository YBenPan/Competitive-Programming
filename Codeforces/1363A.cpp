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
      int input;
      int even_cnt = 0, odd_cnt = 0;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          if (input % 2 == 0)
            even_cnt++;
          else
            odd_cnt++;
        }
      if (odd_cnt == 0)
        {
          cout << "NO" << endl;
          continue;
        }
      bool flag = false;
      for (int i = 1; i <= min(odd_cnt, x); i += 2)
        {
          int even = x - i;
          if (even_cnt >= even)
            {
              flag = true;
            }
        }
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
