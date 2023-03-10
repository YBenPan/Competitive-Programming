#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      vector<int> a(2 * n + 5);
      vector<int> odd;
      vector<int> even;
      for (int i = 1; i <= 2 * n; ++i)
        {
          cin >> a[i];
          if (a[i] % 2 == 1)
            odd.push_back(i);
          else
            even.push_back(i);
        }
      int start1 = 0;
      int start2 = 0;
      if (odd.size() % 2 == 1) // 5 3
        {
          start1++;
          start2++;
        }
      else
        {
          if (odd.size() > 0) {start1 += 2;}
          else {start2 += 2;}
        }
      for (int i = start1; i < odd.size(); i += 2)
        cout << odd[i] << " " << odd[i + 1] << endl;
      for (int i = start2; i < even.size(); i += 2)
        cout << even[i] << " " << even[i + 1] << endl;
    }

  return 0;
}
