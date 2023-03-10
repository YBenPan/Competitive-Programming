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
      if (n < 4)
        {
          cout << -1 << endl;
          continue;
        }
      int index = n;
      if (index % 2 == 0) index--;
      while (index >= 5)
        {
          cout << index << " ";
          index -= 2;
        }
      cout << "3 1 4 2 ";
      index = 6;
      while (index <= n)
        {
          cout << index << " ";
          index += 2;
        }
      cout << endl;
     }
  return 0;
}
