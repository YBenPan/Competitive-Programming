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
      int n, m;
      cin >> n >> m;
      int a[55][55];
      bool col[55] = {false};
      bool row[55] = {false};
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          {
            cin >> a[i][j];
            if (a[i][j] == 1)
              {
                row[i] = true;
                col[j] = true;
              }
          }
      int av_row = n;
      int av_col = m;
      for (int i = 0; i < n; ++i)
        if (row[i]) av_row--;
      for (int i = 0; i < m; ++i)
        if (col[i]) av_col--;
      //cout << av_row << " " << av_col << endl;
      if (min(av_row, av_col) % 2 == 0)
        cout << "Vivek" << endl;
      else
        cout << "Ashish" << endl;
    }
  return 0;
}
