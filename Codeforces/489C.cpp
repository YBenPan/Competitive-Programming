#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, s;
  cin >> m >> s;
  if (s > m * 9)
    {
      cout << "-1 -1" << endl;
      return 0;
    }
  if (s == 0)
    {
      if (m == 1)
        {
          cout << "0 0" << endl;
        }
      else
        {
          cout << "-1 -1" << endl;
        }
      return 0;
    }
  vector<short> num;
  for (int i = 1; i <= 9; ++i)
    {
      int sum = s - i;
      int N = m - 1;
      if (sum > N * 9)
        {
          continue;
        }
      int Num9 = sum / 9;
      int mid = sum % 9;
      num.push_back(i);
      int Num0 = N - Num9 - 1;
      if (mid == 0)
        {
          Num0++;
        }
      for (int j = 0; j < Num0; ++j)
        {
          num.push_back(0);
        }
      if (mid != 0)
        {
          num.push_back(mid);
        }
      for (int j = 0; j < Num9; ++j)
        {
          num.push_back(9);
        }
      if (Num9 == 0)
        {
          while ((int)num.size() < m)
            {
              num.push_back(0);
            }
        }
      for (auto j : num)
        {
          cout << j;
        }
      cout << endl;
      break;
    }
  vector<int> num2;
  for (int i = 0; i <= 9; ++i)
    {
      int sum = s - i;
      int N = m - 1;
      if (sum > N * 9)
        {
          continue;
        }
      int Num9 = sum / 9;
      int mid = sum % 9;
      num2.push_back(i);
      int Num0 = N - Num9 - 1;
      if (mid == 0)
        {
          Num0++;
        }
      for (int j = 0; j < Num0; ++j)
        {
          num2.push_back(0);
        }
      if (mid != 0)
        {
          num2.push_back(mid);
        }
      for (int j = 0; j < Num9; ++j)
        {
          num2.push_back(9);
        }
      if (Num9 == 0)
        {
          while ((int)num.size() < m)
            {
              num2.push_back(0);
            }
        }
      for (int j = num2.size() - 1; j >= 0; j--)
        {
          cout << num2[j];
        }
      cout << endl;
      break;
    }
  return 0;
}
