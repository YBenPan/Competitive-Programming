#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
    {
      int n, m;
      cin >> n >> m;
      int temp[105], l[105], h[105];
      map<int, pair<int, int>> mapp;
      for (int i = 0; i < n; ++i)
        {
          cin >> temp[i] >> l[i] >> h[i];
        }
      int lower_bound = m, upper_bound = m;
      bool flag = true;
      int last_time = 0;
      for (int i = 0; i < n && flag; ++i)
        {
          lower_bound -= (temp[i] - last_time);
          upper_bound += (temp[i] - last_time);
          if (lower_bound > h[i] || upper_bound < l[i])
            flag = false;
          lower_bound = max(lower_bound, l[i]);
          upper_bound = min(upper_bound, h[i]);
          last_time = temp[i];
        }
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  return 0;
}
