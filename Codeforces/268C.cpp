#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  cout << min(n, m) + 1 << endl;
  for (int i = 0; i <= min(n, m); ++i)
    cout << i << " " << min(n, m) - i << endl;
  return 0;
}
