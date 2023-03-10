#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  cout << (a1 + a2 + a3) * (a1 + a2 + a3) - a1 * a1 - a3 * a3 - a5 * a5 << endl;
  return 0;
}
