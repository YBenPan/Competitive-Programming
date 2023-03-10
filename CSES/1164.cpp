#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
using namespace std;
struct customer
{
  int idx, arr, dep;
}a[200005];
bool cmp(const customer &a, const customer &b)
{
  if (a.arr == b.arr) return a.dep < b.dep;
  return a.arr < b.arr;
}
int ans[200005];
priority_queue<pi> room;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    {
      cin >> a[i].arr >> a[i].dep;
      a[i].idx = i;
    }
  sort(a, a + n, cmp);
  /*room.push({1, 2});
  room.push({100, 3});
  room.push({99, 5});
  pair<int, int> topp = room.top();
  cout << topp.first << " " << topp.second << endl;*/
  int room_num = 1;
  int siz = 0;
  for (int i = 0; i < n; ++i)
    {
      if (room.empty())
        {
          ans[a[i].idx] = room_num;
          room.push({-a[i].dep, room_num});
          continue;
        }
      pi minn = room.top();
      if (-minn.first < a[i].arr)
        {
          ans[a[i].idx] = minn.second;
          room.pop();
          room.push({-a[i].dep, minn.second});
        }
      else
        {
          room_num++;
          room.push({-a[i].dep, room_num});
          ans[a[i].idx] = room_num;
        }
      siz = max(siz, (int)room.size());
    }
  cout << siz << endl;
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
