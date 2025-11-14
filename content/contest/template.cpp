#include <bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double dl;
template <typename T, typename P = null_type> using pbds = tree<T, P, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sz(x) (ll)x.size()
#define mod 1000000007
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
const ll inf = LLONG_MAX >> 1;
const double pi = acos(-1.0);
const double eps = 1e-9;
 
void debug(const vector<ll> &v) {for(const ll &x: v) {cout << x << ' ';} cout << endl;}
template<typename T>void o(const T& x, bool space = true) {cout << x;if (space) cout << endl;}
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
template<typename T, typename C, typename Comp> ostream& operator<<(ostream& os, priority_queue<T, C, Comp> pq){os<<"[";while(!pq.empty()){os<<pq.top();pq.pop();if(!pq.empty())os<<", ";}return os<<"]";}
template<typename T, typename Compare> ostream& operator<<(ostream& os, const tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>& t) {os << "[";for (auto it = t.begin(); it != t.end(); ++it) {if (it != t.begin()) os << ", ";os << *it;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],ll n){for(ll i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a*b)%mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a+b)%mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
// If you can't solve a problem with brute force, you likely don't understand it fully yet.
 
ll di[] = {0, 1, 0, -1};
ll dj[] = {1, 0, -1, 0};
string dir = "RDLU";

void solve() {

} // uncomment dbg at the end

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": "; // cout << "Case " << i << ": ";
        solve();
    }
 
    return 0;
}
