//Kadane's
/*
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
  int a[200005];
  for (int i = 0; i < n; ++i) cin >> a[i];
  LL maxx = -(1E16), max_here = 0;
  for (int i = 0; i < n; ++i)
    {
      max_here += a[i];
      maxx = max(maxx, max_here);
      if (max_here < 0) max_here = 0;
    }
  cout << maxx << endl;
  return 0;
}
*/

//Prefix sum
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
  LL pre[200005];
  int input;
  pre[0] = 0;
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      pre[i] = pre[i - 1] + input;
    }
  LL min_prefix_sum = 0, maxx = -1E16;
  for (int i = 1; i <= n; ++i)
    {
      maxx = max(maxx, pre[i] - min_prefix_sum);
      min_prefix_sum = min(min_prefix_sum, pre[i]);
    }
  cout << maxx << endl;
  return 0;
}
