#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--)
    {
      int n, k;
      cin >> n >> k;
      int t, a, b;
      vector<int> v11, v10, v01, v00;
      for (int i = 0; i < n; ++i)
        {
          cin >> t >> a >> b;
          if (a == 1 && b == 1) v11.push_back(t);
          else if (a == 1 && b == 0) v10.push_back(t);
          else if (a == 0 && b == 1) v01.push_back(t);
          else v00.push_back(t);
        }
      sort(v11.begin(), v11.end());
      sort(v10.begin(), v10.end());
      sort(v01.begin(), v01.end());
      int index11 = 0, index10 = 0, index01 = 0;
      LL tot = 0;
      bool flag = true;
      for (int i = 0; i < k && flag; ++i)
        {
          if (index10 == v10.size() || index01 == v01.size())
            {
              if (index11 == v11.size())
                {
                  flag = false;
                  break;
                }
              else
                {
                  tot += v11[index11];
                  index11++;
                }
            }
          else if (index11 == v11.size() || v11[index11] > v10[index10] + v01[index01])
            {
              tot += v10[index10] + v01[index01];
              index10++;
              index01++;
            }
          else
            {
              tot += v11[index11];
              index11++;
            }
        }
      if (flag)
        cout << tot << endl;
      else cout << -1 << endl;
    }

  return 0;
}
