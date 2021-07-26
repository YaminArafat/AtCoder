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
bool vis[200005];
vl adj[200005];
ll n, mn = LONG_MAX;
map<ll,ll>mp;
void DFS(ll src, ll cnt) 
{
    if(src == n)
    {
        see2(src, n);
        mn = min(mn, cnt);
        see2(mn,cnt);
        mp[mn]++;
        return ;
    }
    see2(src, cnt);
    for(int i = 0;i<adj[src].size();i++)
    {
        if(!vis[adj[src][i]])
        {
            vis[src]=true;
            DFS(adj[src][i], cnt+1);
        }
    }
    // clr(vis,false);
}
int main()
{
    fio;
    #ifndef ONLINE_JUDGE 
        rw;
    #endif
    ll m, x, y;
    cin>>n>>m;
    for0(i,m,1)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    DFS(1, 0);
    cout<<mp[mn]<<endl;
    return 0;
}