#include <bits/stdc++.h>
#define LL long long
using namespace std;
int cnt[3], n[3], price[3], maxx[3];
LL r;
LL ans = 0;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  int cnt[3] = {0};
  for (int i = 0; i < str.size(); ++i)
    {
      if (str[i] == 'B') cnt[0]++;
      else if (str[i] == 'S') cnt[1]++;
      else cnt[2]++;
    }
  cin >> n[0] >> n[1] >> n[2];
  cin >> price[0] >> price[1] >> price[2];
  cin >> r;
  LL low = 0;
  LL high = r + 100;
  LL mid;
  while (low <= high)
    {
      mid = (low + high) / 2;
      LL cost = max((LL)0, cnt[0] * mid - n[0]) * price[0] + max((LL)0, cnt[1] * mid - n[1]) * price[1] + max((LL)0, cnt[2] * mid - n[2]) * price[2];
      //cout << mid << " " << cost << endl;
      if (cost < r)
        low = mid + 1;
      else if (cost > r)
        high = mid - 1;
      else break;
    }
  cout << (low + high) / 2 << endl;
  return 0;
}
