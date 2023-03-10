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
      char matrix[55][55];
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          cin >> matrix[i][j];
      bool flag = true;
      for (int i = 0; i < n - 1 && flag; ++i) //rows
        for (int j = 0; j < n - 1 && flag; ++j) //columns
          {
            if (matrix[i][j] == '0')
              continue;
            if (matrix[i + 1][j] == '0' && matrix[i][j + 1] == '0')
              flag = false;
          }
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
