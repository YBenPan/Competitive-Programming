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
      int n, x;
      cin >> n >> x;
      int cnt = 1;
      int a, b;
      for (int i = 0; i < n - 1; ++i)
        {
          cin >> a >> b;
          if (a == x || b == x)
            cnt++;
        }
      if (cnt <= 2)
        cout << "Ayush" << endl;
      else if (n % 2 == 1)
        cout << "Ashish" << endl;
      else
        cout << "Ayush" << endl;
    }

  return 0;
}
