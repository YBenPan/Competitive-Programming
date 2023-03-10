#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  int pre[1005][1005] = {0};
  char ch;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      {
        cin >> ch;
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        if (ch == '*') pre[i][j]++;
      }
  int x1, y1, x2, y2;
  for (int i = 0; i < q; ++i)
    {
      cin >> x1 >> y1 >> x2 >> y2;
      int sum = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
      cout << sum << endl;
    }
  return 0;
}
