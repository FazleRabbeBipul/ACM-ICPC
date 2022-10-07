#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<long long int, long long int>

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;


    vector<pll> adj[n+5];
    vector<ll>in(n+5, 0), out(n+5, 0);
    for(ll i=1; i<=m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
       // adj[v].pb({u, i});
        out[u]++;
        in[v]++;
    }
    ll odd=0, a=0, b=0, c=0;
    for(int i=1; i<=n; i++){
       if(in[i]==out[i])a++;
       else if(in[i]-out[i]==1)b++;
       else if(in[i]-out[i]==-1)c++;
    }

    // cout << "ODD value : " << odd << endl;
    if(!(a==n-2 && b==1 && c==1)){
        cout << "IMPOSSIBLE" << endl;
       // return 0;
    }

    stack<ll>st;
    bool vis[m+5];
    memset(vis, 0, sizeof vis);
    st.push(1);
    vector<ll>path;

    while(st.size()!=0){
        ll u=st.top(), f=0;
        while(!adj[u].empty()){
            pair<ll,ll> x =adj[u].back();
            ll v=x.first, e=x.second;
            adj[u].pop_back();
            if(!vis[e]){
                st.push(v);
                vis[e]=1;
                f=1;
                break;
            }
        }

        if(!f){path.pb(u); st.pop();}
    }

    //if(path.size()!=m+1){ cout<< "IMPOSSIBLE" << endl; return 0;}
    ll u=path[0], v=path[path.size()-1];
    if(u==1 && v==n && path.size()==m+1){
          for(int i=0; i<path.size(); i++) cout << path[i] << " ";
          cout << endl;
    }
    else if(u==n && v==1 && path.size()==m+1){
        for(int i=m; i>=0; i--) cout << path[i] << " ";
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;

}
