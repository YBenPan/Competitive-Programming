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
      int a, b, q;
      cin >> a >> b >> q;
      int num[40005];
      num[0] = 0;
      for (int i = 1; i < a * b; ++i)
        {
          if ((i % a) % b != (i % b) % a)
            num[i] = num[i - 1] + 1;
          else
            num[i] = num[i - 1];
        }
      for (int j = 0; j < q; ++j)
        {
          long long l, r;
          cin >> l >> r;
          long long tot = 0;
          tot += (r / (a * b) * num[a * b - 1] + num[r % (a * b)]);
          tot -= ((l - 1) / (a * b) * num[a * b - 1] + num[(l - 1) % (a * b)]);
          cout << tot << " ";
        }
      cout << endl;
    }
  return 0;
}
