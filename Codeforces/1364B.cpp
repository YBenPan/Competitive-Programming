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
      vector<int> p(n);
      for (int i = 0; i < n; ++i) cin >> p[i];
      vector<int> ans;
      ans.push_back(p[0]);
      char ch;
      if (p[0] < p[1]) ch = '<';
      else ch = '>';
      for (int i = 2; i < n; ++i)
        {
          if (ch == '<')
            {
              if (p[i - 1] > p[i])
                {
                  ans.push_back(p[i - 1]);
                  ch = '>';
                }
            }
          else if (p[i - 1] < p[i])
            {
              ans.push_back(p[i - 1]);
              ch = '<';
            }
        }
      ans.push_back(p[n - 1]);
      cout << ans.size() << endl;
      for (int i : ans) cout << i << " ";
      cout << endl;
    }

  return 0;
}
