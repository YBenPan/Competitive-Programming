#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      vector<int> a;
      int input;
      for (int i = 0; i < n; ++i)
        {
          cin >> input;
          a.push_back(input);
        }
      sort(a.begin(), a.end(), greater<int>());
      for (auto i : a)
        {
          cout << i << " ";
        }
      cout << endl;
    }
  return 0;
}
