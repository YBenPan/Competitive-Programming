#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int N, Q;
int c[500005], tree[500005], last_visit[500005], ans[500005];
struct query
{
  int l;
  int r;
  int idx;
}q[500005];
int lowbit(int x)
{
  return x & -x;
}
void add(int x, int a)
{
  for (int i = x; i <= N; i += lowbit(i)) tree[i] += a;
}
int que(int x)
{
  int sum = 0;
  for (int i = x; i; i -= lowbit(i)) sum += tree[i];
  return sum;
}
bool cmp(const query &i, const query &j)
{
  return i.r < j.r;
}

int main()
{
  //memset(last_visit, -1, sizeof(last_visit));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> Q;
  for (int i = 1; i <= N; ++i) cin >> c[i];
  for (int i = 1; i <= Q; ++i)
    {
      cin >> q[i].l >> q[i].r;
      q[i].idx = i;
    }
  sort(q + 1, q + Q + 1, cmp);
  int next = 1;
  for (int i = 1; i <= Q; ++i)
    {
      for (int j = next; j <= q[i].r; ++j)
        {
          if (last_visit[c[j]]) add(last_visit[c[j]], -1);
          last_visit[c[j]] = j;
          add(j, 1);
         }
      next = q[i].r + 1;
      ans[q[i].idx]  = que(q[i].r) - que(q[i].l - 1);
    }
  for (int i = 1; i <= Q; ++i) cout << ans[i] << endl;
  return 0;
}
/*
#include<iostream>
#include<cmath>
#include<algorithm>

#define ll long long

using namespace std;

const int N = 1e6 + 10;

int tr[N];
int n,m;
int last[N];
int ans[N];
struct node{
        int l,r,pos;
}nod[N];

int color[N];

int lowbit(int x)
{
        return x & -x;
}

void add(int x, int a)
{
        for(int i=x; i<=n; i+=lowbit(i)) tr[i]+=a;
}

int query(int x)
{
        int rul = 0;
        for(int i=x; i; i-=lowbit(i)) rul += tr[i];
        return rul;
}

bool cmp(node a, node b)
{
        return a.r < b.r;
}

int main()
{
        cin>>n>>m;
        for(int i=1; i<=n; i++) scanf("%d",&color[i]);
        for(int i=1; i<=m; i++)
        {
                scanf("%d %d",&nod[i].l,&nod[i].r);
                nod[i].pos = i;
        }
        sort(nod+1, nod+m+1, cmp);
        int next = 1;
        for(int i=1; i<=m; i++)
        {
                for(int j=next; j<=nod[i].r; j++)
                {
                        if(last[color[j]]) add(last[color[j]], -1);
                        last[color[j]] = j;
                        add(j, 1);
                }
                next = nod[i].r+1;
                ans[nod[i].pos] = query(nod[i].r) - query(nod[i].l-1);
        }
        for(int i=1; i<=m; i++)
        {
                cout<<ans[i]<<endl;
        }
        return 0;
}
*/
