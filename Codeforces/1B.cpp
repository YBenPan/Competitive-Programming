#include <bits/stdc++.h>
using namespace std;
bool isNum(char ch)
{
  if (ch - '0' >= 0 && ch - '0' <= 9)
    return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--)
    {
      string str;
      cin >> str;
      bool flag = false;
      int indexOfC;
      if (str[0] == 'R' && isNum(str[1]))
        for (int i = 1; i < str.size() && !flag; ++i)
          if (str[i] == 'C')
            {
              indexOfC = i;
              flag = true;
            }
      if (flag) //RXCY
        {
          int row = 0, col = 0;
          for (int i = 1; i < indexOfC; ++i)
            col = col * 10 + (str[i] - '0');
          for (int i = indexOfC + 1; i < str.size(); ++i)
            row = row * 10 + (str[i] - '0');
          string column;
          while (row > 0)
            {
              if (row % 26 == 0)
                {
                  column.push_back('Z');
                  row = row / 26 - 1;
                }
              else
                {
                  column.push_back(row % 26 + 'A' - 1);
                  row /= 26;
                }
            }
          reverse(column.begin(), column.end());
          cout << column << col << endl;
        }
      else
        {
          string column;
          int indexOfNum;
          for (int i = 0; i < str.size(); ++i)
            if (str[i] >= 'A' && str[i] <= 'Z')
              column.push_back(str[i]);
            else
              {
                indexOfNum = i;
                break;
              }
          int row = 0;
          int mul = 1;
          for (int i = column.size() - 1; i >= 0; --i)
            {
              row += (column[i] - 'A' + 1) * mul;
              mul *= 26;
            }
          int col = 0;
          for (int i = indexOfNum; i < str.size(); ++i)
            {
              col = col * 10 + (str[i] - '0');
            }
          cout << 'R' << col << 'C' << row << endl;
        }
    }
  return 0;
}
