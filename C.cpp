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
const ll mx = 1e6+5;
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

typedef struct COM{
	ll plus,minux,idx;
}com;

bool cmp(const com &aa,const com &bb){
	if(aa.plus==bb.plus)
		return aa.minux < bb.minux;
	return aa.plus < bb.plus;
}

bool f = false;
pi a[mx];
com cm[mx];
ll b[mx];
ll siz[mx];
ll l,r,mid;
vector<vector<pi>> va;

ll LDS(){
	siz[0] = b[0];
	tptp = 1;
	fip(1,n){
		if(siz[0]<b[i])
			siz[0] = b[i];
		else if(siz[tptp-1]>b[i]){
			siz[tptp] = b[i];
			tptp++;
		}else{
			tp = -1;
			l = 0, r = tptp-1;
			while(l<=r){
				m = l + (r-l)/2;
				if(siz[m]<=b[i]){
					tp = m;
					r = m - 1;
				}			
				else
					l = m +1;		
			}
			siz[tp] = b[i];
		}
	}
	return tptp;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
        freopen("error1.txt", "w", stderr);
    #endif // ONLINE_JUDGE

        ll t;
        cin>>t>>m;
        while	(t--){
        	cin>>n;
        	fip(0,n)	
        		cin>>a[i].ff;
        	fip(0,n)	
        		cin>>a[i].ss;
        	fip(0,n){
        		cm[i].plus = a[i].ff+a[i].ss;
        		cm[i].minux = a[i].ff-a[i].ss;
        		cm[i].idx = i;
        	}
        	sort(cm,cm+n,cmp);
        	fip(0,n)
        		b[i] = cm[i].minux;
        	tp = LDS();
        	va.resize(tp);
        	fip(0,tp)
        		va[i].clear();
        	cnt = 1;
        	va[0].push_back({cm[0].minux,cm[0].idx});
        	fip(1,n){
        		tp = cm[i].minux;
        		if(tp<va[cnt-1].back().ff){
        			va[cnt].push_back({tp,cm[i].idx});
        			cnt++;
        			continue;

        		}else if(tp>va[0].back().ff){
        			va[0].push_back({tp,cm[i].idx});        			
        			continue;
        		}
				tp2=-1;
        		l = 0,r = cnt -1;
        		while(l<=r){
        			mid = l + (r-l)/2;
        			if(va[mid].back().ff<=tp){
        				tp2=mid;
        				r = mid -1;
        			}else
        				l = mid + 1;
        		}
        		va[tp2].push_back({tp,cm[i].idx});
        	}
        	// fip(0,va.size())
        	// 	reverse(va[i].begin(),va[i].end());
        	cout<<va.size()<<" 1\n";
        	fip(0,va.size()){
        		cout<<va[i].size()<<" ";
        		fx(va[i])
        			cout<<x.ss+1<<" ";
        		cout<<nli;
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