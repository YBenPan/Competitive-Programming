/*
#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[100005];
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  sort(a, a + n);
  int cnt = 0;
  do
    {
      bool flag = false;
      for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
          flag = true;
      if (!flag)
        {
          for (int i = 0; i < n; ++i) cout << a[i] << " ";
          cout << endl;
          cnt++;
        }
    }while (next_permutation(a, a + n));
  cout << cnt << endl;
  return 0;
}
*/
#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  LL cnt = 1;
  for (int i = 2; i <= n; ++i)
    cnt = cnt * i % MOD;
  LL dec = 1;
  for (int i = 0; i < n - 1; ++i)
    dec = dec * 2 % MOD;
  if (cnt >= dec) cnt -= dec;
  else cnt = cnt + MOD - dec;
  cout << cnt << endl;
  return 0;
}
