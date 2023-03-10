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
      int n, k;
      string str;
      cin >> n >> k;
      cin >> str;
      sort(str.begin(), str.end());
      if (k == 1)
        {
          for (auto i : str)
            cout << i;
          cout << endl;
          continue;
        }
      if (n == 1)
        {
          cout << str[0] << endl;
          continue;
        }
      if (str[k - 1] != str[0])
        {
          //cout << "FIRST CASE\n";
          cout << str[k - 1] << endl;
          continue;
        }
      int j = 0;
      bool flag = true;
      while (j < n - 1 && flag)
        {
          j++;
          if (str[j] != str[0])
            flag = false;
        }
      if (flag)
        {
          //cout << "SECOND CASE\n";
          int length = n / k;
          if (n % k > 0) length++;
          for (int i = 1; i <= length; ++i)
            cout << str[0];
          cout << endl;
          continue;
        }

      /*if (str[j] != str[n - 1])  //cannot be evenly distributed
        {
          cout << "THIRD CASE \n";
          for (int i = j; i < n; ++i)
            cout << str[i];
        }
      else
        {
          cout << "FOURTH CASE \n";
          for (int i = 1; i <= j - n; ++i)
            cout << str[0];
          int remaining = n - j;
          if (remaining % k == 0)
            remaining = remaining / k;
          else
            remaining = remaining / k + 1;
          for (int i = 1; i <= remaining; ++i)
            cout << str[j];
            }*/
      for (int i = 0; i <= j - k; ++i)
        cout << str[0];
      if (str[j] == str[n - 1] && j == k)
        {
          int remaining = n - j;
          if (remaining % k == 0)
            remaining = remaining / k;
          else
            remaining = remaining / k + 1;
          for (int i = 1; i <= remaining; ++i)
            cout << str[j];
          cout << endl;
          continue;
        }
      for (int i = j; i < n; ++i)
        cout << str[i];
      cout << endl;
    }
  return 0;
}
