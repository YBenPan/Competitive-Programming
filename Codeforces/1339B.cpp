#include <bits/stdc++.h>
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
      int input;
      vector<int> a;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          a.push_back(input);
        }
      sort(a.begin(), a.end());
      vector<int> ans;
      int lim = n / 2;
      for (int i = 0; i < lim; ++i)
        {
          ans.push_back(a[n - i - 1]);
          ans.push_back(a[i]);
        }
      if (n % 2 == 1)
        ans.push_back(a[n / 2]);
      for (int i = n - 1; i >= 0; --i)
        cout << ans[i] << " ";
      cout << endl;
    }
  return 0;
}
