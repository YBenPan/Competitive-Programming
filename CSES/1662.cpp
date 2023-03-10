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
  int n;
  cin >> n;
  LL sum = 0, ans = 0;
  map<LL, int> pre;
  pre[0]++;
  int input;
  for (int i = 0; i < n; ++i)
    {
      cin >> input;
      sum = (sum + input % n) % n;
      ans += pre[sum];
      if (sum < 0) ans += pre[n + sum];
      else if (sum > 0) ans += pre[sum - n];
      pre[sum]++;
    }
  cout << ans << endl;
  return 0;
}
