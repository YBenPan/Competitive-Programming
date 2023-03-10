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
      LL n;
      cin >> n;
      LL tot = 0;
      tot += (n / 2);
      if (n % 2 == 1) tot++;
      LL k = 1;
      LL i = 0;
      tot += (n / 2);
      while (k <= n)
        {
          k *= 2;
          tot += (n / k);
        }
      cout << tot << endl;
    }
  return 0;
}
