#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      string s;
      cin >> s;
      int num_occ = 0;
      for (int i = 0; i < s.size() - 6; i++)
        {
          string cur = s.substr(i, 7);
          if (cur == "abacaba") num_occ++;
        }
      if (num_occ > 1) {cout << "No" << endl; continue;}
      else if (num_occ == 1)
        {
          cout << "Yes" << endl;
          for (int i = 0; i < s.size(); ++i)
            if (s[i] == '?') cout << 'd';
            else cout << s[i];
          cout << endl;
        }
      else
        {
          bool flag = false;
          for (int i = s.size() - 7; i >= 0 && !flag; --i)
            {
              string cur = s.substr(i, 7);
              for (int j = 0; j < 7; ++j)
                {
                  if (cur[j] == '?')
                    {
                      if (j == 0 || j == 2 || j == 4 || j == 6)
                        cur[j] = 'a';
                      else if (j == 1 || j == 5)
                        cur[j] = 'b';
                      else cur[j] = 'c';
                    }
                }
              if (cur == "abacaba")
                {
                  string cpy = s;
                  cpy.replace(i, 7, "abacaba");
                  bool found = false;
                  for (int j = 0; j < s.size() - 6 && !found; j++)
                    {
                      string cur = cpy.substr(j, 7);
                      if (cur == "abacaba" && j != i)
                        found = true;
                    }
                  if (!found)
                    {
                      flag = true;
                      s.replace(i, 7, "abacaba");
                    }
                }
            }
          if (flag)
            {
              cout << "Yes" << endl;
              for (int i = 0; i < s.size(); ++i)
                if (s[i] == '?') cout << 'd';
                else cout << s[i];
            }
          else cout << "No";
          cout << endl;
        }
    }

  return 0;
}
