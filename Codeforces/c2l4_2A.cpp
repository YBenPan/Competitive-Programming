#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> a;
struct node
{
  int pref, suf, sum, seg;
};
vector<node> tree;
void buildTree(int L, int R, int treeNode)
{
  //cout << L << " " << R << " " << treeNode << endl;
  if (L == R)
    {
      tree[treeNode].seg = a[L];
      tree[treeNode].suf = a[L];
      tree[treeNode].pref = a[L];
      tree[treeNode].sum = a[L];
      return;
    }
  int mid = (L + R) / 2;
  buildTree(L, mid, 2 * treeNode + 1);
  buildTree(mid + 1, R, 2 * treeNode + 2);
  tree[treeNode].pref = max(tree[2 * treeNode + 1].pref, tree[2 * treeNode + 1].sum + tree[2 * treeNode + 2].pref);
  tree[treeNode].suf = max(tree[2 * treeNode + 2].suf, tree[2 * treeNode + 2].sum + tree[2 * treeNode + 1].suf);
  tree[treeNode].seg = max(tree[2 * treeNode + 1].seg, max(tree[2 * treeNode + 2].seg, tree[2 * treeNode + 1].suf + tree[2 * treeNode + 2].pref));
  tree[treeNode].sum = tree[2 * treeNode + 1].sum + tree[2 * treeNode + 2].sum;
}
/*
node sum(int L, int R, int treeNode, int qL, int qR)
{
  //cout << L << " " << R << " " << treeNode << endl;
  if (L >= qL && R <= qR) // included
    {
      return tree[treeNode];
    }
  else if (L > qR || R < qL)
    return {0, 0, 0, 0};
  else
    {
      int mid = (L + R) / 2;
      node a, b;
      a = sum(L, mid, 2 * treeNode + 1, qL, qR);
      b = sum(mid + 1, R, 2 * treeNode + 2, qL, qR);
      return s;
    }
}*/
void treeSet(int num, int L, int R, int treeNode, int target)
{
  if (L == R)
    {
      tree[treeNode].seg = num;
      tree[treeNode].suf = num;
      tree[treeNode].pref = num;
      tree[treeNode].sum = num;
      return;
    }
  int mid = (L + R) / 2;
  if (target <= mid)
    treeSet(num, L, mid, 2 * treeNode + 1, target);
  else
    treeSet(num, mid + 1, R, 2 * treeNode + 2, target);
  tree[treeNode].pref = max(tree[2 * treeNode + 1].pref, tree[2 * treeNode + 1].sum + tree[2 * treeNode + 2].pref);
  tree[treeNode].suf = max(tree[2 * treeNode + 2].suf, tree[2 * treeNode + 2].sum + tree[2 * treeNode + 1].suf);
  tree[treeNode].seg = max(tree[2 * treeNode + 1].seg, max(tree[2 * treeNode + 2].seg, tree[2 * treeNode + 1].suf + tree[2 * treeNode + 2].pref));
  tree[treeNode].sum = tree[2 * treeNode + 1].sum + tree[2 * treeNode + 2].sum;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int input;
  for (int i = 0; i < n; ++i) {cin >> input; a.push_back(input);}
  int power = 1;
  while (power < n) power *= 2;
  tree.assign(2 * power, {0LL, 0LL, 0LL, 0LL});
  buildTree(0, n - 1, 0);
  /*for (int i = 0; i < 2 * n - 1; ++i)
    cout << tree[i] << endl;*/
  int qA, qB;
  if (tree[0].seg < 0) cout << 0 << endl;
  else cout << tree[0].seg << endl;
  for (int i = 0; i < m; ++i)
    {
      cin >> qA >> qB;
      treeSet(qB, 0, n - 1, 0, qA);
      if (tree[0].seg < 0) cout << 0 << endl;
      else cout << tree[0].seg << endl;
    }
  return 0;
}
