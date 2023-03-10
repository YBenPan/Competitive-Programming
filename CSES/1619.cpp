#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
struct s
{
  int time;
  int type;
}rec[400005];
bool cmp(const s &a, const s &b)
{
  return a.time < b.time;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a, b;
  for (int i = 0; i < n; ++i)
    {
      cin >> a >> b;
      rec[2 * i].time = a; rec[2 * i].type = 1;
      rec[2 * i + 1].time = b; rec[2 * i + 1].type = -1;
    }
  sort(rec, rec + 2 * n, cmp);
  int cur = 0;
  int maxx = 0;
  for (int i = 0; i < 2 * n; ++i)
    {
      cur += rec[i].type;
      maxx = max(maxx, cur);
    }
  cout << maxx << endl;
  return 0;
}
