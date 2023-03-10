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
  vector<int> a(n);
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
  if (n == 2)
    {
      cout << 2 << endl;
      return 0;
    }
  l[0] = 1;
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
    else l[i] = 1;
  r[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i)
    if (a[i] < a[i + 1]) r[i] = r[i + 1] + 1;
    else r[i] = 1;
  int maxx = max(r[1] + 1, l[n - 2] + 1);
  //for (int i = 0; i < n; ++i) cout << l[i] << " " << r[i] << endl;
  for (int i = 1; i < n - 1; ++i)
    if (a[i - 1] < a[i + 1] - 1) maxx = max(maxx, l[i - 1] + 1 + r[i + 1]);
    else maxx = max(maxx, max(l[i - 1] + 1, r[i + 1] + 1));
  maxx = max(maxx, r[0]);
  cout << maxx << endl;
  return 0;
}
