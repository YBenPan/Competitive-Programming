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
      vector<int> vec(n);
      int maxx = 0;
      for (int i = 0; i < n; ++i)
        {cin >> vec[i]; maxx = max(maxx, vec[i]);}
      sort(vec.begin(), vec.end());
      int num = -1;
      for (int i = 1; i <= 1024; ++i)
        {
          set<int> ans;
          for (int j = 0; j < n; ++j)
            ans.insert(vec[j] ^ i);
          int k = 0;
          bool flag = true;
          for (auto j : ans)
            {
              if (j != vec[k]) {flag = false; break;}
              k++;
            }
          if (flag)
            {
              num = i;
              break;
            }
        }
      cout << num << endl;
    }
  return 0;
}
