#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll,ll> pi;
typedef map<ll,ll> mi;
typedef long double ld;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef pair<ld,ld> pd;
#define ff first
#define ss second
#define srt(a) sort(a.begin(),a.end());
#define fip(k, n) for (ll i = k; i < n; i++)
#define fjp(k, n) for (ll j = k; j < n; j++)
#define fin(k, n) for (ll i = k; i >= n; i--)
#define fjn(k, n) for (ll j = k; j >= n; j--)
#define fp(k, n, m) for (ll k = n; k < m; k++)
#define fn(k, n, m) for (ll k = n; k >= m; k--)
#define ordered_set tree<pi, null_type,less< pi >, rb_tree_tag,tree_order_statistics_node_update>
#define totalOne(n) __builtin_popcount(n)
#define backZero(n) __builtin_ctzll(n)
#define frontZero(n) __builtin_clzll(n)
#define fx(k) for ( auto x : k )
#define test ll t;cin >> t;while (t--)
#define nli "\n"

ll n,m,tp,tp2,res,cnt,ans,sum,tptp;
const ll mx = 2e5+5;
//const ll mod = 1e9+7;
//vector<vector<ll>> dp(mx+1);
//void factorial_sieve();
//void prime_sieve();
// ll gcd(ll a,ll b);
// ll power(ll a,ll b);

// typedef struct Disjoint_Set_Union{
//     ll par[mx], size[mx];
//     ll srcparent,destparent;
//     void init(ll k){
//         fip(0,k)
//             par[i] = i, size[i] = 1;
//     }
//     ll findParent(ll x){
//         return par[x] == x ? x : par[x] = findParent(par[x]);
//     }
//     bool unite(ll src, ll dest){
//         srcparent = findParent(src);
//         destparent = findParent(dest);
//         if(srcparent != destparent){
//             if(size[srcparent] < size[destparent])
//                 swap(srcparent,destparent);
//             par[destparent] = srcparent;
//             size[srcparent] += size[destparent];
//             return true;
//         }
//         else 
//             return false;
//     }
// }DSU;

bool f = false;vi adj[mx];
ll u,v;
ll b[mx];
ll dis[mx];
ll mxdis[mx];
ll parent[mx];
vvi par;

void dfs(ll src,ll par, ll diss){
    dis[src] = diss;
    fx(adj[src])
        if(x!=par)
            parent[x] = src,dfs(x,src,diss+1);
    return;
}

ll dfs2(ll src, ll par){
    ll diss = dis[src];
    fx(adj[src])
        if(x!=par)
            diss = max(diss,dfs2(x,src));
    mxdis[src] = diss;
    return mxdis[src];
}

vi vv;

ll findpar(ll idx,ll tc){
    bitset<32> bit(tc);
    vv.clear();
    fip(0,32)
        if(bit[i])
            vv.push_back(i+1);
    sum = idx;
    fx(vv)
        idx = par[idx][x];
    return idx;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
        freopen("error1.txt", "w", stderr);
    #endif // ONLINE_JUDGE

        test{
            cin>>n;
            fip(0,n+3)
                adj[i].clear();
            fip(0,n-1){
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            cin>>m;
            fip(0,m)
                cin>>tp>>b[i];
            parent[tp] = tp;
            dfs(tp,-1,0);
            dfs2(tp,-1);
            tptp = log2(n);
            tptp += 3;
            par.resize(n+5,vi(tptp));
            fip(1,n+1)
                par[i][0] = i,par[i][1] = parent[i];
            fip(2,tptp)
                fjp(1,n+1)
                    par[j][i] = par[par[j][i-1]][i-1];
            // fip(1,n+1)
            //     fjp(0,tptp)
            //         cout<<i<<" "<<j<<" "<<par[i][j]<<nli;
            fip(0,m){
                tp2 = b[i];
                cnt = (dis[tp2] - 1) >> 1;
                ans = findpar(tp2,cnt);
                // cout<<findpar(tp2,cnt)<<nli;
                ans = mxdis[ans];
                cout<<ans<<nli;
            }
        }
        
    cerr << "Time elapsed: " << setprecision(6) << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}


// void factorial_sieve(){
//     fip(1,mx+1)
//         for(ll j = i; j<=mx; j+=i)  
//             fs[j].push_back(i); 
//     return; 
// }
// void prime_sieve(){ 
//     for(ll i = 2; i*i<=mx;i++)  
//         if(dp[i])   
//             for(ll j = i*i; j<mx; j+=i) 
//                 dp[j] = false;  
//         dp[1] = dp[0] = false;  
//     return; 
// }
// ll gcd(ll a,ll b){
//     return (a==0) ? b : (gcd(b%a,a));
// }
// ll res;
// ll power(ll a,ll b){
//     b %= (mod-1);
//     res = 1;
//     a %= mod;
//     while(b > 0){
//         if(b & 1)
//             res = (res * (a%mod)) % mod;
//         b = b >> 1;
//         a = ((a%mod) * (a%mod)) % mod;
//     }
//     return res;
// }