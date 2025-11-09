#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008

using namespace std;

vii G[100];
int mark[100];
int n , ed;

void BFS(int nn)
{
    //cout << nn << " ";
    mark[nn] = 1;
    queue < int > q;

    q.push(nn);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " " ;

        for (int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!mark[v]){
                q.push(v);
                mark[v] = 1;
            }
        }
    }
}

int main()
{
    cout << "Input number of node and edge ";
    cin >> n >> ed;

    cout << "Insert the edges " << endl;

    for (int i=0;i<ed;i++){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int source ;
    cout << "Input source :";
    cin >> source;
    BFS(source);
    cout << endl;

    return 0;
}
