#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--)
    {
      int n, k;
      cin >> n >> k;
      vector<long long> a;
      long long input;
      long long max_a = 0;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          a.push_back(input);
          max_a = max(max_a, input);
        }
      if (max_a == 0)
        {
          cout << "YES" << endl;
          continue;
        }
      long long dec = max_a;
      long long max_i = 0;
      while (dec >= k)
        {
          dec /= k;
          max_i++;
        }
      //cout << max_i << endl;
      long long power = pow(k, max_i);
      bool outer_flag = true;
      //cout << power << endl;
      for (int i = max_i; i >= 0 && outer_flag; --i)
        {
          bool flag = true;
          int cnt = 0;
          for (int j = 0; j < n && flag; ++j)
            {
              if (a[j] >= power)
                {
                  a[j] -= power;
                  ++cnt;
                  if (cnt > 1)
                    {
                      //cout << i << endl;
                      flag = false;
                    }
                }
            }
          if (!flag)
            {
              cout << "NO" << endl;
              outer_flag = false;
            }
          power /= k;
        }
      if (outer_flag)
        {
          for (long long i = 0; i < n; ++i)
            {
              if (a[i] != 0)
                {
                  outer_flag = false;
                }
            }
          if (outer_flag)
            {
              cout << "YES" << endl;
            }
          else
            {
              cout << "NO" << endl;
            }
        }
    }
  return 0;
}
