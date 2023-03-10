#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi = vector<int>;
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, n;
  multiset<int> ms;
  cin >> x >> n;
  ms.insert(x);
  set<int> light;
  int input;
  for (int i = 0; i < n; ++i)
    {
      cin >> input;
      light.insert(input);
      int target, rep1, rep2;
      if (light.size() == 1)
        {
          target = x;
          rep1 = x - input;
          rep2 = input;
        }
      else
        {
          auto pos = light.find(input);
          if (pos == --light.end())
            {
              auto low = --pos;
              target = x - *low;
              rep1 = input - *low;
              rep2 = x - input;
            }
          else if (pos == light.begin())
            {
              auto up = ++pos;
              target = *up;
              rep1 = input;
              rep2 = *up - input;
            }
          else
            {
              auto low = --pos;
              pos++;
              auto up = ++pos;
              target = *up - *low;
              rep1 = input - *low;
              rep2 = *up - input;
            }
        }
      //cout << target << " " << rep1 << " " << rep2 << endl;
      ms.erase(ms.find(target));
      ms.insert(rep1);
      ms.insert(rep2);

      //for (auto j = ms.begin(); j != ms.end(); ++j) cout << *j << " " ;
      cout << *ms.rbegin() << " ";
      //cout << endl;
    }
  cout << endl;
  return 0;
}
