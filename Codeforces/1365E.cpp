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
  LL a[505];
  for (int i = 0; i < n; ++i) cin >> a[i];
  LL maxx = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        maxx = max(maxx, a[i] | a[j] | a[k]);
  cout << maxx << endl;
  return 0;
}
