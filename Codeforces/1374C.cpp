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
      int n;
      cin >> n;
      string str;
      cin >> str;
      while (str.find("()") != string::npos)
        {
          int found = str.find("()");
          str.erase(found, 2);
        }
      cout << str.size() / 2 << endl;
    }

  return 0;
}
