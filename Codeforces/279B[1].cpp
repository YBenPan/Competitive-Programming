#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;
  cin >> n >> t;
  int input;
  vector<long long> sum;
  sum.push_back(0);
  for (int i = 1; i <= n; ++i)
    {
      cin >> input;
      sum.push_back(sum[i - 1] + input);
    }
  int max_t = 0;
  /*
  if (n == 1)
    {
      if (sum[0] <= t)
        cout << 1 << endl;
      else
        cout << 0 << endl;
      return 0;
    }*/
  for (int i = 0; i <= n; ++i)
    {
      int left = i + 1;
      int right = n;
      int j = i;
      while (left <= right)
        {
          int mid = (left + right) / 2;
          if (sum[mid] - sum[i] <= t)
            {
              j = mid;
              left = mid + 1;
            }
          else
            {
              right = mid - 1;
            }
        }
      max_t = max(max_t, j - i);
    }
  cout << max_t << endl;
  return 0;
}
