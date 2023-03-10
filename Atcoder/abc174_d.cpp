#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  string str;
  cin >> str;
  int red_cnt = 0;
  for (int i = 0; i < str.size(); ++i)
    if (str[i] == 'R') red_cnt++;
  int cnt_R = 0, cnt_W = 0;
  for (int i = 0; i < red_cnt; ++i)
    {
      if (str[i] == 'R') cnt_R++;
      else cnt_W++;
    }
  cout << cnt_W << endl;
  return 0;
}
