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

struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b){
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u;
    }
    else {
    	parent[v] = u;
    	rank[u]++;
    }
}
/// DSU + just sort according weight in increasing order.then process if same comp then skip else union them. sum
int main(){
	ll N, M;
	cin >>N >>M;
	vector<node> edges;
	for(int i=0; i<M; i++){
        ll u, v, wt;
        cin >>u >>v >>wt;
        edges.pb(node(u,v,wt));
        edges.pb(node(v,u,wt));
	}
	sort(edges.begin(), edges.end(), comp);

	vector<int> parent(N);
	for(int i = 0;i<N;i++)
	    parent[i] = i;
	vector<int> rank(N, 0);

	int cost = 0;
	vector<pair<int,int>> mst;
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt;
	        mst.push_back({it.u, it.v});
	        unionn(it.u, it.v, parent, rank);
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl;
	return 0;
}
