#include <bits/stdc++.h>
using namespace std;
struct cmp
{
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
  {
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena == lenb)
      return a.first < b.first;
    return lena > lenb;
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  set<pair<int, int>, cmp> segs;
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      segs.insert({0, n - 1});
      vector<int> a(n);
      for (int i = 1; i <= n; ++i)
        {
          pair<int, int> cur = *segs.begin();
          segs.erase(segs.begin());
          int mid = (cur.second + cur.first) / 2;
          a[mid] = i;
          if (cur.first < mid) segs.insert({cur.first, mid - 1});
          if (mid < cur.second) segs.insert({mid + 1, cur.second});
        }
      for (auto i : a)
        cout << i << " ";
      cout << endl;
    }
  return 0;
}
