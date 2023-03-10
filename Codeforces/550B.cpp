#include <bits/stdc++.h>
using namespace std;
int n, l, r, x;
vector<int> c;
int tot = 0;
void choose(int minn, int maxx, int sum, int i)
{
  if (i >= n)
    {
      if (sum >= l && sum <= r && maxx - minn >= x)
        tot++;
      return;
    }
  choose(min(minn, c[i]), max(maxx, c[i]), sum + c[i], i + 1);
  choose(minn, maxx, sum, i + 1);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> l >> r >> x;
  int input;
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      c.push_back(input);
    }
  sort(c.begin(), c.end());
  choose(1000001, 0, 0, 0);
  cout << tot << endl;
  return 0;
}
