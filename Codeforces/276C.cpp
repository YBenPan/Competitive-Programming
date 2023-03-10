#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
      cnt[i] = 0;
    }
  sort(a.begin(), a.end());
  int l, r;
  for (int i = 0; i < q; ++i)
    {
      cin >> l >> r;
      l--;
      r--;
      cnt[l]++;
      if (r + 1< n)
        cnt[r + 1]--;
    }
  long long count = 0;
  vector<int> query(n);
  for (int i = 0; i < n; ++i)
    {
      count += cnt[i];
      query[i] = count;
    }
  sort(query.begin(), query.end());
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    {
      sum += (long long)query[i] * a[i];
    }
  cout << sum << endl;
  return 0;
}
