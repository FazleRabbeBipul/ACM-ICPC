#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector<ll>G[200005];
ll vis[200005], clr[200005];
bool okh=true;
ll n, m;

void bfs(ll u, ll c){
    queue<ll>q;
    vis[u]=1;
    clr[u]=c;
    q.push(u);
    while(!q.empty()){
        auto u=q.front();
        vis[u]=1;
        q.pop();
        for(auto it: G[u]){
            if(vis[it]){
                if(clr[it]==clr[u])okh=false;
            }
            else{
                clr[it]=1-clr[u];
                q.push(it);
                vis[it];
            }
        }
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
    for(int i=1; i<=n; i++){
       if(!vis[i]){
          bfs(i, 1);
       }
    }
    if(!okh) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1; i<=n; i++){
            cout << clr[i]+1 << " ";
        }
        cout << endl;
    }
}
///https://cses.fi/problemset/result/4415008/
