#include <bits/stdc++.h>
#define LL long long
using namespace std;
string str;
int calc(char c, string s)
{
  if (s.size() == 1) return s[0] != c;
  int mid = s.size() / 2;
  int cnt1 = s.size() / 2 - count(s.begin(), s.begin() + mid, c) + calc((char)c + 1, s.substr(mid));
  int cnt2 = s.size() / 2 - count(s.begin() + mid, s.end(), c) + calc((char)c + 1, s.substr(0, mid));
  return min(cnt1, cnt2);
}
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
      cin >> str;
      int ans = calc('a', str);
      cout << ans << endl;
    }

  return 0;
}
