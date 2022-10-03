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
ll vis[200005], p[200005], d[200005];
bool okh=true;
ll n, m;

///display the shortest path from the source to some vertex u
void printPath(int u){
  if(!vis[u]) cout << "No path!";
  else{
     vector<int> path;
     for(int v = u; v != -1; v = p[v]) path.push_back(v);
     reverse(path.begin(), path.end());
     cout << "Path: ";
     for (int v : path) cout << v << " ";
  }
}

void bfs(ll u){
    queue<ll>q;
    vis[u]=1;
    q.push(u);
    d[u]=0;
    p[u]=-1;
    cout << u << " ";
    while(!q.empty()){
        auto u=q.front();
        vis[u]=1;
        q.pop();
        for(auto it: G[u]){
          if(!vis[it]){
            vis[it] = true;
            q.push(it);
            d[it] = d[u] + 1;
            p[it] = u;
          }
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> n ;
    for(int i=0; i<n-1; i++){
        ll u, v;
        cin >>u >>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=1; i<=n; i++){
       if(!vis[i]){
          bfs(i);
          ///cout << endl;
       }
    }

    ll u;
    cin >> u;
    printPath(u);
}
