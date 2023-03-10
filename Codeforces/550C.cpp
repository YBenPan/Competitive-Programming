#include <bits/stdc++.h>
using namespace std;
bool mltp[1005];
void generate()
{
  for (int i = 0; i <= 1000; ++i)
    if (i % 8 == 0)
      mltp[i] = true;
    else
      mltp[i] = false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string num;
  cin >> num;
  generate();
  int n = num.size();
  for (int i = 0; i < n; ++i)
    if (mltp[num[i] - 48])
      {
        cout << "YES" << endl << num[i] << endl;
        return 0;
      }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      {
        int res = (num[i] - 48) * 10 + (num[j] - 48);
        if (mltp[res])
          {
            cout << "YES" << endl << res << endl;
            return 0;
          }
      }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      for (int k = j + 1; k < n; ++k)
        {
          int res = (num[i] - 48) * 100 + (num[j] - 48) * 10 + (num[k] - 48);
          if (mltp[res])
            {
              cout << "YES" << endl;
              cout << res << endl;
              return 0;
            }
        }
  cout << "NO" << endl;
  return 0;
}
