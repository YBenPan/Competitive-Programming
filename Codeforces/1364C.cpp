#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  bool in_a[100005] = {false};
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
      b[i] = -1;
      if (i > 0 && a[i] != a[i - 1])
        b[i] = a[i - 1];
      in_a[a[i]] = true;
    }
  int cur = 0;
  for (int i = 0; i < n; ++i)
    {
      while (in_a[cur]) cur++;
      if (b[i] == -1) {b[i] = cur; in_a[cur] = true;}
    }
  bool in_b[100005] = {false};
  for (int i = 0; i < n; ++i)
    {
      if (in_b[b[i]]) {cout << -1 << endl; return 0;}
      in_b[b[i]] = true;
    }
  for (int i : b) cout << i << " ";
  cout << endl;
  return 0;
}
