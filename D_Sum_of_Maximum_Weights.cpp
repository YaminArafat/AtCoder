#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for0(i, n, incr) for (int i = 0; i < (int)(n); i+=incr) 
#define for1(i, n, incr) for (int i = 1; i <= (int)(n); i+=incr) 
#define forc(i, l, r, incr) for (int i = (int)(l); i <= (int)(r); i+=incr) 
#define forcr(i, r, l, decr) for (int i = (int)(r); i >= (int)(l); i-=decr)
#define forr0(i, n, decr) for (int i = (int)(n) - 1; i >= 0; i-=decr)
#define forr1(i, n, decr) for (int i = (int)(n); i >= 1; i-=decr) 
#define see(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define see2(x,y) cout<<"\n"<<#x<<" = "<<(x)<<" "<<#y<<" = "<<(y)<<'\n'
#define see3(x,y,z) cout<<"\n"<<#x<<" = "<<(x)<<" "<<#y<<" = "<<(y)<<" "<<#z<<" = "<<(z)<<'\n'
#define clr(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rw freopen("input.txt","r",stdin);freopen("output.txt","w",stdout); 
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
vi adj[100005];
map<pii, int> cost;
bool vis[100005];
vi vv;
int ans2;
int bfs(int src)
{
    queue<int> q;
    q.push(src);
    int ans = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        // cout << p << " " << adj[p].size() << endl;
        vis[p] = true;
        for0(i, adj[p].size(), 1)
        {
            if (!vis[adj[p][i]] && adj[p][i] > p)
                ans += cost[{p, adj[p][i]}], q.push(adj[p][i]); // vv.pb(cost[{p, adj[p][i]}]), q.push(adj[p][i]); //cout << p << " " << adj[p][i] << endl;
        }
    }
    clr(vis, false);
    return ans;
}
void dfs(int src)
{
    vis[src] = true;
    for0(i, adj[src].size(), 1)
    {
        if (adj[src][i] <= src)
            continue;
        if (!vis[adj[src][i]])
            /* vv.pb(cost[{src, adj[src][i]}]),*/ ans2 += cost[{src, adj[src][i]}], dfs(adj[src][i]);
    }
}
int arr[100005];
int main()
{
    fio;
#ifndef ONLINE_JUDGE
    rw;
#endif
    int n, u, v, w, ans = 0;
    cin >> n;
    for0(i, n - 1, 1)
    {
        cin >> u >> v >> w;
        if (v < u)
            swap(u, v);
        arr[v] = w;
        // adj[u].pb(v);
        // adj[v].pb(u);
        // cost[mk(u, v)] = w;
        // cost[mk(v, u)] = w;
    }
    for (int i = 2; i <= n; i++)
    {
        ans += (i - 1) * arr[i];
        // cout << arr[i] << endl;
    }
    // for1(i, n, 1)
    // {
    //     ans2 = 0;
    //     dfs(i);
    //     ans += ans2;
    //     clr(vis, false);
    // }
    // for (int i = 0; i < vv.size(); i += 1)
    // {
    //     ans += (i + 1) * vv[i];
    //     // cout << vv[i] << endl;
    // }
    cout << ans << endl;
    return 0;
}