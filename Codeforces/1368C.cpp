#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector< pair<int, int> > ans;
  if (n == 1)
    {
      cout << 15 << endl;
      cout << "2 0" << endl;
      cout << "3 0" << endl;
      cout << "4 0" << endl;
      cout << "2 1" << endl;
      cout << "4 1" << endl;
      cout << "0 2" << endl;
      cout << "1 2" << endl;
      cout << "2 2" << endl;
      cout << "3 2" << endl;
      cout << "4 2" << endl;
      cout << "0 3" << endl;
      cout << "2 3" << endl;
      cout << "0 4" << endl;
      cout << "1 4" << endl;
      cout << "2 4" << endl;
      return 0;
    }
  int cnt = 0;
  int mid_y;
  if (n % 2 == 0) mid_y = 1;
  else mid_y = 3;
  for (int i = 0; i < n / 2; ++i)
    {
      ans.push_back({4, mid_y++});
      cnt++;
      for (int i = 2; i <= 6; ++i)
        ans.push_back({i, mid_y});
      cnt += 5;
      mid_y++;
      ans.push_back({2, mid_y}); ans.push_back({4, mid_y}); ans.push_back({6, mid_y});
      cnt += 3;
      mid_y++;
      for (int i = 2; i <= 6; ++i)
        ans.push_back({i, mid_y});
      mid_y++;
      cnt += 5;
    }
  ans.push_back({4, mid_y++}); cnt++;
  for (int i = 0; i <= 4; ++i) ans.push_back({i, mid_y});
  cnt += 5;
  int bottom = 0;
  if (n % 2 == 1) bottom = 2;
  for (int i = mid_y - 1; i >= bottom; --i) ans.push_back({0, i});
  cnt += (mid_y - bottom);
  for (int i = 1; i <= 4; ++i) ans.push_back({i, bottom});
  cnt += 4;
  if (n % 2 == 1)
    {
      ans.push_back({4, 0});
      ans.push_back({4, 1});
      ans.push_back({5, 2});
      ans.push_back({6, 2});
      ans.push_back({6, 1});
      ans.push_back({6, 0});
      ans.push_back({5, 0});
      cnt += 7;
    }
  cout << cnt << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
