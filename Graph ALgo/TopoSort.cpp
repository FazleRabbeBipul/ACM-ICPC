#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
ll vis[200005], visArr[200005];
vector<ll>g[200005];
bool okh = true;
vector<ll>path;
ll n, m;

void dfs(ll u){
   vis[u]=1;
   visArr[u]=1;
   for(auto it: g[u]){
      if(!vis[it])dfs(it);
      else if(visArr[it]){/// visArr[1] means, this node has been activated already.
        okh=false;
        return;
      }
      if(!okh)return;
   }

   visArr[u]=0; /// visArr[0]=this node get turn off/ complete.
   if(!okh)return;

   path.pb(u);/// push into toposort serial.
}

int main(){
  cin >>n >>m;
  for(int i=0; i<m; i++){
    ll u, v;
    cin >> u >> v;
    g[u].pb(v);
  }
  for(int i=1; i<=n; i++){
    if(!vis[i] && okh)dfs(i);
  }

  if(!okh) cout << "IMPOSSIBLE" << endl;
  else{
    reverse(path.begin(), path.end());
    for(auto it: path) cout << it << " ";
    cout << endl;
  }
}
///https://cses.fi/problemset/result/4433245/
