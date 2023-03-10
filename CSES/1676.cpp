#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int parent[100005], ht[100005]; 
int n, m, max_size = 0, cnt; 
void init()
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i; 
        ht[i] = 1; 
    }
}
int get(int s)
{
    return s == parent[s] ? s : get(parent[s]); 
}
void unite(int a, int b)
{
    a = get(a); b = get(b); 
    if (a == b) return; 
    cnt--; 
    if (ht[a] < ht[b]) swap(a, b);
    parent[b] = a;
    ht[a] += ht[b]; 
    max_size = max(max_size, ht[a]); 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m; 
    cnt = n; 
    int in1, in2; 
    init(); 
    for (int i = 0; i < m; ++i)
    {
        cin >> in1 >> in2;
        unite(in1, in2); 
        cout << cnt << " " << max_size << endl;
    }
    return 0;
}