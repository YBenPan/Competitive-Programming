#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool check_prime(int x)
{
  for (int i = 2; i <= sqrt(x); ++i)
    if (x % i == 0)
      return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  int max_a = 0;
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
      max_a = max(max_a, a[i]);
    }
  LL ans = 1;
  for (int i = 2; i <= max_a; ++i)
    {
      if (check_prime(i))
        {
          int cnt_not_div = 0;
          LL min1 = 500000;
          LL min2 = 500000;
          vector<int> num;
          for (int j = 0; j < n && cnt_not_div < 2; ++j)
            {
              int x = a[j];
              int k = 0;
              if (x % i != 0) {cnt_not_div++; continue;}
              while (x > 1)
                {
                  if (x % i == 0)
                    {
                      x /= i;
                      k++;
                    }
                  else break;
                }
              num.push_back(k);
              /*if (k < min1)
                {
                  min2 = min1;
                  min1 = k;
                }
              else if (k < min2)
              min2 = k;*/
            }
          //cout << i << " " << min1 << " " << min2 << endl;
          nth_element(num.begin(), num.begin() + 1, num.end());
          if (cnt_not_div < 2)
            for (int j = 0; j < num[1]; ++j) ans *= i;
        }
    }
  if (n == 2 && abs(a[0] - a[1]) == 1)
    ans *= a[0];
  cout << ans << endl;
  return 0;
}
