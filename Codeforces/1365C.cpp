#include <bits/stdc++.h>
#define LL long long
using namespace std;
int pos_a[200005], pos_b[200005], ld[200005], rd[200005], lft[200005], rght[200005];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int x;
  for (int i = 1; i <= n; ++i)
    {
      cin >> x;
      pos_a[x] = i;
    }
  int y;
  for (int i = 1;i <= n; ++i)
    {
      cin >> y;
      pos_b[y] = i;
    }
  //cout << pos_a[1] << " " << pos_b[1] << endl;
  for (int i = 1; i <= n; ++i)
    {
      if (pos_a[i] > pos_b[i])
        {
          rd[i] = pos_a[i] - pos_b[i];
          ld[i] = n - rd[i];
        }
      else
        {
          ld[i] = pos_b[i] - pos_a[i];
          rd[i] = n - ld[i];
        }
      lft[ld[i]]++;
      rght[rd[i]]++;
    }
  int maxx = 0;
  for (int i = 0; i < n; ++i)
    {
      maxx = max(maxx, lft[i]);
      maxx = max(maxx, rght[i]);
      //cout << lft[i] << " " << rght[i] << endl;
    }
  cout << maxx << endl;
  return 0;
}
