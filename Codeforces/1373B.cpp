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
      int cnt0 = 0;
      int cnt1 = 0;
      for (int i = 0; i < str.size(); ++i)
        if (str[i] == '0') cnt0++;
        else cnt1++;
      int minn = min(cnt0, cnt1);
      if (minn % 2 == 0) cout << "NET" << endl;
      else cout << "DA" << endl;
    }

  return 0;
}
