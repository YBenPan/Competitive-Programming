#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      string input;
      cin >> n;
      cin >> input;
      vector<int> a, b;
      char first = 'x';
      for (int i = 0; i < n; ++i)
        {
          int x = input[i] - 48;
          if (x == 0)
            {
              a.push_back(0);
              b.push_back(0);
            }
          else if (x == 1)
            {
              if (first == 'x')
                {
                  first = 'a';
                  a.push_back(1);
                  b.push_back(0);
                }
              else
                {
                  a.push_back(0);
                  b.push_back(1);
                }
            }
          else if (x == 2)
            {
              if (first == 'a')
                {
                  a.push_back(0);
                  b.push_back(2);
                }
              else
                {
                  a.push_back(1);
                  b.push_back(1);
                }
            }
        }
      for (auto i : a)
        {
          cout << i;
        }
      cout << endl;
      for (auto i : b)
        {
          cout << i;
        }
      cout << endl;
    }
  return 0;
}
