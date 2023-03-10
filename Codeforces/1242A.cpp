#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  LL n;
  cin >> n;
  bool prime = true;
  bool power = true;
  LL init = 1;
  for (int i = 2; i <= sqrt(n); ++i)
    {
      if (n % i == 0)
        {
          prime = false;
          init = i;
          LL n1 = n;
          while (n1 > 1 && power)
            {
              if (n1 % i == 0)
                n1 /= i;
              else
                power = false;
            }
          if (power)
            cout << i << endl;
          else
            cout << 1 << endl;
          return 0;
        }
    }
  cout << n << endl;
  return 0;
}
