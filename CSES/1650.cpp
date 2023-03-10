#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  int pre[200005], input;
  pre[0] = 0;
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      pre[i] = pre[i - 1] ^ input;
    }
  int a, b;
  for (int i = 0; i < q; ++i)
    {
      cin >> a >> b;
      cout << (pre[b] ^ pre[a - 1]) << endl;
    }
  return 0;
}
