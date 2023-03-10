#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  if (n == 1)
    {
      cout << 1 << endl;
      return 0;
    }
  vector<int> a, b;
  a.push_back(-1);
  b.push_back(-1);
  for (int i = 0; i < n; ++i)
    {
      if (str[i] == 'a')
        a.push_back(i);
      else
        b.push_back(i);
    }
  a.push_back(n);
  b.push_back(n);
  int maxx = 0;
  for (int i = 1; i <= b.size() - 1; ++i)
    {
      int lim = i + k;
      if (lim >= b.size()) lim = b.size() - 1;
      maxx = max(maxx, b[lim] - b[i - 1] - 1);
    }
  for (int i = 1; i <= a.size() - 1; ++i)
    {
      int lim = i + k;
      if (lim >= a.size()) lim = a.size() - 1;
      maxx = max(maxx, a[lim] - a[i - 1] - 1);
    }
  cout << maxx << endl;
  return 0;
}
