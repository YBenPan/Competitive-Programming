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
  int a[200005];
  for (int i = 0; i < N; ++i) cin >> a[i];
  sort(a, a + N, greater<int>());
  LL ans = a[0];
  int j = 1;
  for (int i = 1; i <= N - 2; ++i)
    {
      ans += a[j];
      if (i % 2 == 0) j++;
    }
  cout << ans << endl;
  return 0;
}
