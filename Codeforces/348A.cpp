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
  LL sum = 0;
  LL tot = 0;
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
      tot = max(tot, (LL)a[i]);
      sum += a[i];
    }
  if (sum % (n - 1) == 0) sum /= (n - 1);
  else sum = sum / (n - 1) + 1;
  tot = max(tot, sum);
  cout << tot << endl;
  return 0;
}
