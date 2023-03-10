#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
  return a.second < b.second;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> cus(m);
  multiset<int> tic;
  int input;
  for (int i = 0; i < n; ++i)
    {
      cin >> input;
      tic.insert(input);
    }
  for (int i = 0; i < m; ++i)
    {
      cin >> input;
      auto it = tic.upper_bound(input);
      if (tic.empty() || it == tic.begin()) cout << -1 << endl;
      else
        {
          --it;
          cout << *it << endl;
          tic.erase(it);
        }
    }
  return 0;
}
