#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a;
  int input;
  for (int i = 0; i < n; ++i)
    {
      cin >> input;
      a.push_back(input);
    }
  sort(a.begin(), a.end());
  int tot = 1;
  int sum = 0;
  sum = a[0];
  for (int i = 1; i < n; ++i)
    {
      if (a[i] >= sum)
        {
          sum += a[i];
          ++tot;
        }
    }
  cout << tot << endl;
  return 0;
}
