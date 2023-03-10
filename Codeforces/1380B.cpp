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
      string str;
      cin >> str;
      int cnt_R = 0, cnt_S = 0, cnt_P = 0;
      for (char i : str)
        if (i == 'R') cnt_R++;
        else if (i == 'S') cnt_S++;
        else cnt_P++;
      int maxx = max(cnt_R, max(cnt_S, cnt_P));
      char ch;
      if (maxx == cnt_R) ch = 'P';
      else if (maxx == cnt_S) ch = 'R';
      else if (maxx == cnt_P) ch = 'S';
      for (int i = 0; i < str.size(); ++i) cout << ch;
      cout << endl;
    }

  return 0;
}
