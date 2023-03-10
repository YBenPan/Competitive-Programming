#include <bits/stdc++.h>
using namespace std;
int lowest_divisor(int x)
{
  for (int i = 2; i <= sqrt(x); ++i)
    {
      if (x % i == 0)
        return i;
    }
  return 1;
}
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
      int tot = 0;
      vector<int> a;
      int input;
      vector<int> result;
      int color[32] = {0};
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          int num = lowest_divisor(input);
          if (color[num] == 0)
            {
              color[num] = ++tot;
            }
          result.push_back(color[num]);
        }
      cout << tot << endl;
      for (auto i : result)
        cout << i << " ";
      cout << endl;
    }
}
