#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int a[200005];
int N, K;
int check(int M)
{
  int cnt = 0;
  for (int i = 0; i < N; ++i)
    {
      cnt += (a[i] - 1) / M;
    }
  if (cnt <= K)
    return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> K;
  int maxx = 0;
  for (int i = 0; i < N; ++i)
    {
      cin >> a[i];
      maxx = max(a[i], maxx);
    }
  int L = 0, R = maxx;
  while (L + 1 < R)
    {
      int mid = (L + R) / 2;
      if (check(mid)) R = mid;
      else L = mid;
    }
  cout << R << endl;
  return 0;
}
