#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
set<int> diff;
multiset<int> seg;
string str;
void modify(int x)
{
  if (x == 0 || x == str.size()) return;
  auto it = diff.find(x);
  if (it == diff.end()) // not found. insert
    {
      diff.insert(x);
      it = diff.find(x);
      auto a = *prev(it), b = *next(it);
      seg.erase(seg.find(b - a));
      seg.insert(x - a);
      seg.insert(b - x);
    }
  else //found. remove
    {
      auto a = *prev(it), b = *next(it);
      seg.erase(seg.find(x - a));
      seg.erase(seg.find(b - x));
      seg.insert(b - a);
      diff.erase(it);
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> str;
  diff.insert(0); diff.insert(str.size());
  for (int i = 1; i < str.size(); ++i)
    if (str[i - 1] != str[i]) diff.insert(i);
  for (auto it = diff.begin(); next(it) != diff.end(); ++it)
    seg.insert(*next(it) - *it);
  //for (auto i : seg) cout << i << " " ;
  int m;
  cin >> m;
  int input;
  for (int i = 0; i < m; ++i)
    {
      cin >> input;
      modify(input - 1);
      modify(input);
      /*if (i == 0)
        {
          for (auto i : diff) cout << i << " " ;
          cout << endl;
          for (auto i : seg) cout << i << " ";
          cout << endl;
        }
      */
      cout << *seg.rbegin() << " ";
    }
  return 0;
}
