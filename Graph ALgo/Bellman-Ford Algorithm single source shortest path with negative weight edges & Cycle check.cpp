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
vector<int>col(200005), in(200005), out(2000005);
int timer=0;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
vector<int> vis;
struct edge
{
    int a, b, cost;
};
ll n, m, v;
vector<edge> e;
void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;///source
    vector<int> p (n, - 1);
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cout << "No negative cycle from " << v;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y]; /// entry into loop

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
}

/*
8 9
1 2 -12
2 3 -3
3 4 -2
4 1 15
1 5 1
5 6 1
6 7 1
7 8 1
8 4 1
1
*/


int main(){
    cin >> n >>m;
    for(int i=0; i<m; i++){
        ll u, v, w;
        cin >>u >>v >> w;
        edge x;
        x.a=u; x.b=v; x.cost=w;
        e.pb(x);
    }
    cin >> v;///source
    solve();
}
