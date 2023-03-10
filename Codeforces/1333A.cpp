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
      int n, m;
      cin >> n >> m;
      if (n % 2 == 1 && m % 2 == 1)
        {
          for (int i = 1; i <= n; ++i)
            {
              for (int j = 1; j <= m; ++j)
                if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0))
                  cout << "B";
                else
                  cout << "W";
              cout << endl;
            }
        }
      else
        {
          cout << "BB";
          for (int i = 3; i <= m; ++i)
            if (i % 2 == 1)
              cout << "B";
            else
              cout << "W";
          cout << endl;
          for (int i = 2; i <= n; ++i)
            {
              for (int j = 1; j <= m; ++j)
                if ((i % 2 ==1 && j % 2 ==1) || (i % 2 == 0 && j % 2 == 0))
                  cout << "B";
                else
                  cout << "W";
              cout << endl;
            }
        }
    }
  return 0;
}
