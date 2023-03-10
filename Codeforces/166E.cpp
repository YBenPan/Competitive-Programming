#include <bits/stdc++.h>
using namespace std;
int main()
{
  const int MOD = 1000000007;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long dp_D, dp_ABC;
  dp_D = 0;
  dp_ABC = 3;
  long long next_D, next_ABC;
  for (int i = 2; i <= n; ++i)
    {
      next_D = dp_ABC % MOD;
      next_ABC = (3 * dp_D % MOD + dp_ABC * 2 % MOD) % MOD;
      dp_D = next_D;
      dp_ABC = next_ABC;
    }
  cout << dp_D << endl;
  return 0;
}
