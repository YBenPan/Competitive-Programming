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
      vector<int> pos0, pos1;
      int ans[200005];
      string s;
      int n;
      cin >> n;
      cin >> s;
      for (int i = 0; i < n; ++i)
        {
          int pos = pos0.size() + pos1.size();
          if (s[i] == '1')
            {
              if (pos0.empty())
                pos1.push_back(pos);
              else
                {
                  pos = pos0.back();
                  pos0.pop_back();
                  pos1.push_back(pos);
                }
            }
          else
            {
              if (pos1.empty())
                pos0.push_back(pos);
              else
                {
                  pos = pos1.back();
                  pos1.pop_back();
                  pos0.push_back(pos);
                }
            }
          ans[i] = pos;
        }
      cout << pos0.size() + pos1.size() << endl;
      for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << " ";
      cout << endl;
    }

  return 0;
}
