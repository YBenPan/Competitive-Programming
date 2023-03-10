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
      cin >> n;
      int a[200005];
      for (int i = 0; i < n; ++i)
        {
          cin >> a[i];
        }
      int k = 1;
      vector<short> color;
      color.push_back(1);
      for (int i = 1; i < n - 1; ++i)
        {
          int available = -1;
          if (a[i] == a[i - 1])
            {
              color.push_back(1);
              continue;
            }
          for (int j = 1; j <= k; ++j)
            {
              if (color[i - 1] != j)
                {
                  available = j;
                }
            }
          if (available == -1)
            {
              color.push_back(++k);
            }
          else
            {
              color.push_back(available);
            }
        }
      if (a[n - 2] == a[n - 1] && a[n - 1] == a[0])
        {
          color.push_back(color[0]);
        }
      else if (a[n - 2] == a[n - 1] && a[n - 1] != a[0])
        {
          int available = -1;
          if (color[n - 2] != color[0])
            {
              color.push_back(color[n - 2]);
            }
          else
            {
              for (int j = 1; j <= k; ++j)
                {
                  if (color[n - 2] != j && color[0] != j)
                    {
                      available = j;
                    }
                }
              if (available == -1)
                {
                  color.push_back(++k);
                }
              else
                {
                  color.push_back(available);
                }
            }
        }
      else if (a[0] == a[n - 1] && a[n - 1] != a[n - 2])
        {
          int available = -1;
          if (color[0] != color[n - 2])
            {
              color.push_back(color[0]);
            }
          else
            {
              for (int j = 1; j <= k; ++j)
                {
                  if (color[n - 2] != j && color[0] != j)
                    {
                      available = j;
                    }
                }
              if (available == -1)
                {
                  color.push_back(++k);
                }
              else
                {
                  color.push_back(available);
                }
            }
        }
      else
        {
          int available = -1;
          for (int j = 1; j <= k; ++j)
            {
              if (color[n - 2] != j && color[0] != j)
                {
                  available = j;
                }
            }
          if (available == -1)
            {
              color.push_back(++k);
            }
          else
            {
              color.push_back(available);
            }
        }
      cout << k << endl;
      for (auto i : color)
        {
          cout << i << " ";
        }
      cout << endl;
    }
  return 0;
}
