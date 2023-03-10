#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 2; i <= n; ++i)
    {
      bool flag = true;
      for (int j = 2; j <= sqrt(i); ++j)
        if (i % j == 0)
          flag = false;
      if (flag)
        {
          int x = i;
          while (x <= n)
            {
              ans.push_back(x);
              x *= i;
            }
        }
    }
  cout << ans.size() << endl;
  for (int i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}
