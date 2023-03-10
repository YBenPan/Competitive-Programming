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
      string b;
      cin >> b;
      string a;
      a.push_back(b[0]);
      for (int i = 1; i < b.size() - 1; i += 2)
        a.push_back(b[i]);
      a.push_back(b[b.size() - 1]);
      for (char i : a) cout << i;
      cout << endl;
    }

  return 0;
}
