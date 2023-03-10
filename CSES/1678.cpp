/* 
    If we reach a vertex that is already on the stack, then there is a cycle. Start
    We visit neighbors that aren't black
        If our vertex is still on stack (middle of cycle), then continue the cycle
        If our vertex is not on stack, then we reached the start of the cycle. Stop
*/ 
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define MOD 1000000007
#define vi vector<int>
#define pi pair<int, int>
int n, m;
vi g[100005]; 
bool visited[100005] = {0}, is_stack[100005] = {0}; 
vi cycle; 
bool dfs(int s)
{
    visited[s] = 1; 
    is_stack[s] = 1;
    for (auto i : g[s])
    {
        if (is_stack[i]) //cycle found. Start
        {
            cycle.pb(i); 
            cycle.pb(s);
            is_stack[i] = is_stack[s] = 0; 
            return true; 
        }
        else if (!visited[i])
        {
            if (dfs(i)) // cycle
            {
                if (is_stack[s]) // middle of a cycle
                {
                    cycle.pb(s); 
                    is_stack[s] = 0; 
                    return true; 
                }
                else //reached the beginning of the cycle again. Stop search. 
                {
                    cycle.pb(s); 
                    return false; 
                }
            }
            if (!cycle.empty()) return false; //Once we found a cycle, immediately stop. 
        }
    }
    is_stack[s] = 0;
    return false; 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int in1, in2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> in1 >> in2;
        g[in1].pb(in2); 
    }
    for (int i = 1; i <= n && cycle.empty(); ++i)
        if (!visited[i])
        {
            dfs(i); 
        }
    if (cycle.empty()) {cout << "IMPOSSIBLE" << endl; return 0;}
    reverse(cycle.begin(), cycle.end()); 
    cout << cycle.size() << endl;
    for (auto i : cycle) cout << i << " ";
    cout << endl;
    return 0;
}