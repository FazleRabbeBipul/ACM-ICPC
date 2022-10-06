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

vector<pll>G[200005];
ll n, m;
vector<int>col(200005), in(200005), out(2000005);
int timer=0;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
vector<int>d, p, vis;

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;
    for(int v=t; v!=s; v=p[v]) path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(int s, vector<int> & d, vector<int> & p){

    d.assign(n+1, INF);
    p.assign(n+1, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) /// check if it is an important pair or if it is already an old and handled pair.
            continue;    /// updated dis match then pick or skip. it is important else it could be O(nm)

        for (auto edge : G[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{

    cin >> n >>m;
    for(int i=0; i<m; i++){
        ll u, v, w;
        cin >>u >>v >> w;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    int source; cin >> source;
    dijkstra(source, d, p);
    for(int i=1; i<=n; i++) cout << d[i] << " ";
    int goal;
    cin >> goal;
    vector<int>path = restore_path(source, goal, p);
    for(auto it : path) cout << it << " ";
    cout << endl;
}
