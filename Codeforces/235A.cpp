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
  if (n == 1)
    cout << 1 << endl;
  else if (n == 2)
    cout << 2 << endl;
  else if (n % 2 == 1)
    cout << n * (n - 1) * (n - 2) << endl;
  else
    {
      if (n % 3 == 0)
        cout << (n - 1) * (n - 2) * (n - 3) << endl;
      else
        cout << n * (n - 1) * (n - 3) << endl;
    }
  return 0;
}
