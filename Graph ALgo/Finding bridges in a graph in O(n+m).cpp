#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ALL(s)  (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define show(x)  cout << #x << " : " << x << endl
#define     fast        ios_base::sync_with_stdio(false);cin.tie(NULL)
template<class T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;//indexed_set<ll> st;st.order_of_key(x);
const long long  mod = 1000000007;

vector<ll>G[200005];
ll p[200005], d[200005];
ll n, m;
vector<int> tin, low;
vector<bool>vis;
int timer;

void IS_BRIDGE(int u, int to){
    cout << "bridge edge " << u << " -> " << to << endl;
}
/// low[u] = min(tin[u], tin[p], low[to]);
    /// tin[p]=for each node p that is connected to node u via a back-edge (u,p)
    /// low[to] = for all to for which (v, to) is a tree Edge
///the current edge(u,to)in the DFS tree is a bridge if and only if low[to]>tin[u].

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for(int to : G[u]) {
        if(to == p) continue;
        if(vis[to]){
            low[u] = min(low[u], tin[to]);
        }else{
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > tin[u])
                IS_BRIDGE(u, to);///is some function that will process the fact that edge (a,b) is a bridge edge
                                /// for example, print it.
        }
    }
}

void find_bridges(){
    timer = 0;
    vis.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for(int i=0; i<n; ++i){
        if(!vis[i]) dfs(i);
    }
}

int main()
{
    cin >> n >>m;
    for(int i=0; i<m; i++){
        ll u, v;
        cin >>u >>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    find_bridges();
}
