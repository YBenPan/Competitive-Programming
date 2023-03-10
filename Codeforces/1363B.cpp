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
      int n = str.size();
      int num1 = 0;
      int num0 = 0;
      for (int i = 0; i < n; ++i)
        if (str[i] == '0')
          num0++;
        else num1++;
      int i0 = 0;
      int i1 = 0;
      int minn = 1000;
      minn = min(minn, num0);
      minn = min(minn, num1);
      for (int i = 0; i < n; ++i)
        {
          if (str[i] == '0')
            i0++;
          else i1++;
          int rem0 = num0 - i0;
          int rem1 = num1 - i1;
          //cost to change to 11000
          int cost10 = i0 + rem1;
          int cost01 = i1 + rem0;
          //cout << i << " " << cost10 << " " << cost01 << endl;
          minn = min(minn, cost10);
          minn = min(minn, cost01);
        }
      cout << minn << endl;
    }

  return 0;
}
