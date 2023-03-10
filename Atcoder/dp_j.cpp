#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
double dp[305][305][305];
int N;
double dfs(int a, int b, int c)
{
  if (a == 0 && b == 0 && c == 0) return 0;
  if (dp[a][b][c]) return dp[a][b][c];
  double res = 1.0 * N / (a + b + c);
  if (a) res += 1.0 * a / (a + b + c) * dfs(a - 1, b, c);
  if (b) res += 1.0 * b / (a + b + c) * dfs(a + 1, b - 1, c);
  if (c) res += 1.0 * c / (a + b + c) * dfs(a, b + 1, c - 1);
  return dp[a][b][c] = res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  int a[4];
  memset(a, 0, sizeof(a));
  int in;
  for (int i = 0; i < N; ++i)
    {
      cin >> in;
      a[in]++;
    }
  memset(dp, 0, sizeof(dp));
  cout << setprecision(20) << dfs(a[1], a[2], a[3]) << endl;
  return 0;
}
