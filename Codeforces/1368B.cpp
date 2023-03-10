#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  LL k;
  cin >> k;
  if (k == 1) {cout << "codeforces" << endl; return 0;}
  int cnt[10];
  for (int i = 0; i < 10; ++i) cnt[i] = 1;
  int i = 1;
  LL product = 1;
  int prev = 1;
  int cur = 2;
  while (product < k)
    {
      product /= prev;
      product *= cur;
      i++;
      cnt[(i - 2) % 10]++;
      if ((i - 1) % 10 == 0)
        {
          prev++;
          cur++;
        }
    }
  for (int i = 0; i < cnt[0]; ++i) cout << 'c';
  for (int i = 0; i < cnt[1]; ++i) cout << 'o';
  for (int i = 0; i < cnt[2]; ++i) cout << 'd';
  for (int i = 0; i < cnt[3]; ++i) cout << 'e';
  for (int i = 0; i < cnt[4]; ++i) cout << 'f';
  for (int i = 0; i < cnt[5]; ++i) cout << 'o';
  for (int i = 0; i < cnt[6]; ++i) cout << 'r';
  for (int i = 0; i < cnt[7]; ++i) cout << 'c';
  for (int i = 0; i < cnt[8]; ++i) cout << 'e';
  for (int i = 0; i < cnt[9]; ++i) cout << 's';
  cout << endl;
  return 0;
}
