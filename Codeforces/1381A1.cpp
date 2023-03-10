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
      string a, b;
      cin >> a;
      cin >> b;
      vector<int> ans;
      for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
          {
            ans.push_back(i + 1);
            ans.push_back(1);
            ans.push_back(i + 1);
          }
      cout << ans.size() << " ";
      for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
      cout << endl;
    }

  return 0;
}
