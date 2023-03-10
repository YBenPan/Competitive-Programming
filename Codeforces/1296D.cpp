#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  vector<int> h(n);
  vector<int> numTimes(n);
  for (int i = 0; i < n; ++i)
    cin >> h[i];
  for (int i = 0; i < n; ++i)
    {
      int hl = h[i] % (a + b);
      if (hl == 0)
        hl += b;
      else
        hl -= a;
      //cout << hl << " ";
      if (hl <= 0)
        numTimes[i] = 0;
      else if (hl % a == 0)
        numTimes[i] = hl / a;
      else
        numTimes[i] = hl / a + 1;
    }
  sort(numTimes.begin(), numTimes.end());
  int tot = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    {
      tot += numTimes[i];
      if (tot > k)
        break;
      cnt++;
      }
  cout << cnt << endl;
  return 0;
}
