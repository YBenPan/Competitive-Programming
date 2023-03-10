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
      vector<int> a(n);
      int numOdd = 0;
      int numEven = 0;
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
          if (a[i] % 2 == 1)
            numOdd++;
          else
            numEven++;
        }
      if (numOdd % 2 == 0 && numEven % 2 == 0)
        {
          cout << "YES" << endl;
          continue;
        }
      sort(a.begin(), a.end());
      bool neighbor = false;
      for (int i = 0; i < n - 1 && !neighbor; ++i)
        if (a[i + 1] - a[i] == 1)
          neighbor = true;
      if (neighbor)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
