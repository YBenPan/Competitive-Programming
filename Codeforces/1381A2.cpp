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
      vector<int> ans1, ans2, ans;
      for (int i = 0; i < a.size() - 1; ++i)
        if (a[i] != a[i + 1]) {ans1.push_back(i + 1); ans.push_back(i + 1);}
      if (a[n - 1] == '1') {ans1.push_back(n); ans.push_back(n);}
      for (int i = 0; i < b.size() - 1; ++i)
        if (b[i] != b[i + 1]) ans2.push_back(i + 1);
      if (b[n - 1] == '1') {ans2.push_back(n);}
      for (int i = ans2.size() - 1; i >= 0; --i)
        ans.push_back(ans2[i]);
      cout << ans.size() << " ";
      for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
      cout << endl;
    }

  return 0;
}
