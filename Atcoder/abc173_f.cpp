#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  LL ans = 0;
  for (int i = 1; i <= N; ++i)
    ans += ((LL)i * (N - i + 1));
  int a, b;
  for (int i = 0; i < N - 1; ++i)
    {
      cin >> a >> b;
      if (a > b) swap(a, b);
      ans -= ((LL)a * (N - b + 1));
    }
  cout << ans << endl;
  return 0;
}
