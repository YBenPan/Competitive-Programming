#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  LL a[3];
  cin >> a[0] >> a[1] >> a[2];
  cout << "First" << endl;
  cout.flush();
  for (int i = 0; i < 3; ++i)
    {
      vector<LL> b = {a[0], a[1], a[2]};
      sort(b.begin(), b.end());
      LL y = 2LL * b[2] - b[1] - b[0];
      if (b[2] - b[1] == b[1] - b[0]) y = b[1] - b[0];
      cout << y << endl; cout.flush();
      int dec;
      cin >> dec;
      if (dec == 0) return 0;
      a[dec - 1] += y;
    }
  return 0;
}
