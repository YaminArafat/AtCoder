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
string s;
char arr[8]={'c','h','o','k','u','d','a','i'};
ll dp[100005];
ll call(ll si, ll xi)
{
    cout<<"incoming"<<endl;
    see2(si,xi);
    if(xi == 8)
    {
        cout<<"returning 1"<<endl;
        return 1;
    }
    if(si == s.size())
    {
        cout<<"returning 0"<<endl;
        return 0;
    }
    ll ret=0;
    if(s[si] == arr[xi])
    {
        see(dp[si]);
        if(dp[si] != -1)
            return dp[si];
        see2(si,xi);
        cout<<"match->calling si+1 xi+1"<<endl;
        see2(si+1,xi+1);
        ret += call(si+1, xi+1);
        cout<<"1st call returned somthing"<<endl;
        see(ret);
        cout<<"2nd call si+1 xi"<<endl;
        see2(si+1,xi);
        ret += call(si+1, xi);
        cout<<"2nd call returned"<<endl;
        see(ret);
    }
    else
    {
        cout<<"mismtach ,calling nxt si+1"<<endl;
        see2(si+1,xi);
        ret += call(si+1, xi);
    }
    cout<<"final retrurn"<<endl;
    see2(si,ret);
    return dp[si] = ret;
}
int main()
{
    fio;
    #ifndef ONLINE_JUDGE 
        rw;
    #endif
    cin>>s;
    clr(dp,-1);
    cout<<call(0,0)<<endl;
    return 0;
}