#include <bits/stdc++.h>
using namespace std;
int max_length = 0;
int n;
vector<int> s;
void search(int length, int index)
{
  max_length = max(length, max_length);
  for (int i = index * 2; i <= n; i += index)
    {
      cout << index << " " << i << endl;
      if (s[i] > s[index])
        {
          search(length + 1, i);
        }
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    {
      cin >> n;
      s.resize(n + 1);
      for (int i = 1; i <= n; ++i)
        cin >> s[i];
      max_length = 1;
      search(1, 1);
      cout << max_length << endl;
    }
  return 0;
}
