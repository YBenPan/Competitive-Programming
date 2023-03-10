#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int arr[10] = {0};
  string str;
  cin >> str;
  for (int i = 0; i < n; ++i)
    {
      int num = str[i] - 48;
      for (int j = 2; j <= num; ++j)
        arr[j]++;
    }
  arr[2] = arr[2] + 2 * arr[4] + 3 * arr[8] + arr[6];
  arr[3] = arr[3] + arr[9] * 2 + arr[6];
  while (arr[7] > 0)
    {
      arr[7]--;
      arr[5]--;
      arr[3] -= 2;
      arr[2] -= 4;
      cout << 7;
    }
  while (arr[5] > 0)
    {
      arr[2] -= 3;
      arr[3]--;
      arr[5]--;
      cout << 5;
    }
  while (arr[3] > 0)
    {
      arr[3]--;
      arr[2]--;
      cout << 3;
    }
  while (arr[2] > 0)
    {
      arr[2]--;
      cout << 2;
    }
  cout << endl;
  return 0;
}
