#include <bits/stdc++.h>
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
      set<int> a;
      int input;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          a.insert(input);
        }
      cout << a.size() << endl;
    }
  return 0;
}
