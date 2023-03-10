#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
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
      vector<int> a(n + 1);
      for (int i = 1; i <= n; ++i) a[i] = str[i - 1] - '0';
      int s = 0;
      unordered_map<int, int> mp;
      mp[0]++;
      for (int i = 1; i <= n; ++i)
        {
          s += a[i];
          mp[s - i]++;
        }
      LL tot = 0;
      for (auto x : mp)
        {
          int cur = x.second;
          tot += (LL)cur * (cur - 1) / 2;
        }
      cout << tot << endl;
    }

  return 0;
}
