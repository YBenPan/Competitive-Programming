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
  LL sum = 0;
  for (int i = 1; i <= N; ++i)
    {
      int end = (N / i) * i;
      int start = i;
      int num = (end - start) / i + 1;
      sum += (LL)(end + start) * num / 2;
    }
  cout << sum << endl;
  return 0;
}
