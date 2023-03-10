#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
vector< pair<int, int> > ans;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int i = a, j = b, k = 1;
  for (int cnt_i = 0; cnt_i < n; cnt_i++)
    {
      for (int cnt_j = 0; cnt_j < m; cnt_j++)
        {
          ans.push_back({i, j});
          j++;
          if (j > m) j = 1;
        }
      j--;
      if (j == 0) j = m;
      i++;
      if (i > n) i = 1;
    }
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
