#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
struct element
{
  int num;
  int sign;
};
bool cmp(element a, element b)
{
  return a.num > b.num;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<element> a;
  int in;
  int neg_cnt = 0, pos_cnt = 0;
  for (int i = 0; i < n; ++i)
    {
      cin >> in;
      if (in < 0) {a.push_back({-in, -1}); neg_cnt++;}
      else {a.push_back({in, 1}); pos_cnt++;}
    }
  sort(a.begin(), a.end(), cmp);
  /*for (int i = 0; i < n; ++i)
    cout << a[i].sign << " " << a[i].num << endl;*/
  LL product = 1;
  if (neg_cnt == 0)
    {
      for (int i = 0; i < k; ++i)
        product = product * (LL)a[i].num % MOD;
      cout << product << endl;
      return 0;
    }
  if (pos_cnt == 0)
    {
      product = 1;
      for (int i = n - 1; i > n - k - 1; --i)
        product = product * a[i].num % MOD;
      cout << (LL)(MOD - product) % MOD << endl;
      return 0;
    }
  pos_cnt = 0;
  neg_cnt = 0;
  for (int i = 0; i < k; ++i)
    if (a[i].sign == -1) neg_cnt++; else pos_cnt++;
  if (neg_cnt % 2 == 0)
    {
      product = 1;
      for (int i = 0; i < k; ++i)
        product = product * (LL)a[i].num % MOD;
      cout << product << endl;
      return 0;
    }
  int pos_left = 1E9;//least positive in first K. Abs as low as possible
  int neg_right = 0;//least negative in N - K. Abs as high as possible
  int neg_left = 0;//largest negative in K. Abs as low as possible
  int pos_right = 0;//largest positive in N - K. Abs as high as possible
  for (int i = 0; i < k; ++i)
    {
      if (a[i].sign == 1) pos_left = min(pos_left, a[i].num);
      else neg_left = min(neg_left, a[i].num);
    }
  for (int i = k; i < n; ++i)
    {
      if (a[i].sign == 1) pos_right = max(pos_right, a[i].num);
      else neg_right = max(neg_right, a[i].num);
    }
  LL app1 = neg_right * neg_left;
  LL app2 = pos_left * pos_right;
  product = 1;
  if (app1 > app2)
    {
      for (int i = 0; i < k; ++i)
        {
          if (a[i].sign == 1 && a[i].num == pos_left) continue;
          else product = product * (LL)a[i].num % MOD;
        }
      product = product * neg_right % MOD;
    }
  else
    {
      for (int i = 0; i < k; ++i)
        {
          if (a[i].sign == -1 && a[i].num == neg_left) continue;
          else product = product * (LL)a[i].num % MOD;
        }
      product = product * pos_right % MOD;
    }
  cout << product << endl;
  return 0;
}
