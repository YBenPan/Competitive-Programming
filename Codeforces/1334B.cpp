#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
    {
      int n, x;
      cin >> n >> x;
      vector<int> a;
      int input;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          a.push_back(input);
        }
      sort(a.begin(), a.end(), greater<int>());
      long long sum = 0;
      int index = 0;
      for (int i = 0; i < n; ++i)
        {
          sum += a[i];
          if (sum / (i + 1) >= x)
            index++;
          else
            break;
        }
      cout << index << endl;
    }
  return 0;
}
