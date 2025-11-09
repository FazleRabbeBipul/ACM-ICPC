#include<bits/stdc++.h>
using namespace std;
const int maxn = 100009;
int ara[maxn];

struct _node{
    int zeros, ones, twos;
    _node(){
        zeros = ones = twos = 0;
    }
}segtree[4 * maxn];
int lazy[4 * maxn];

void Merge(_node &res, _node lft, _node rgh)
{
    res.zeros = lft.zeros + rgh.zeros;
    res.ones = lft.ones + rgh.ones;
    res.twos = lft.twos + rgh.twos;
}

void build(int node, int beg, int ed)
{
    if(beg == ed){
        if(ara[beg] % 3 == 0) segtree[node].zeros++;
        else if(ara[beg] % 3 == 1) segtree[node].ones++;
        else segtree[node].twos++;
        return;
    }

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    build(lft, beg, mid);
    build(rgh, mid + 1, ed);

    Merge(segtree[node], segtree[lft], segtree[rgh]);
}


void relax(int node, int beg, int ed)
{
    if(lazy[node] % 3 == 1){
        int tmp = segtree[node].zeros;
        segtree[node].zeros = segtree[node].twos;
        segtree[node].twos = segtree[node].ones;
        segtree[node].ones = tmp;
    }
    else if(lazy[node] % 3 == 2){
        int tmp = segtree[node].zeros;
        segtree[node].zeros = segtree[node].ones;
        segtree[node].ones = segtree[node].twos;
        segtree[node].twos = tmp;
    }

    int lft = 2 * node;
    int rgh = lft + 1;
    if(beg != ed){
        lazy[lft] += lazy[node];
        lazy[rgh] += lazy[node];
    }
    lazy[node] = 0;
}

void rangeUpdate(int node, int beg, int ed, int i, int j)
{
    if(lazy[node]) relax(node, beg, ed);

    if(beg > j || ed < i) return;
    if(beg >= i && ed <= j){
        lazy[node]++;
        return;
    }

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    rangeUpdate(lft, beg, mid, i, j);
    rangeUpdate(rgh, mid + 1, ed, i, j);

    Merge(segtree[node], segtree[lft], segtree[rgh]);

}

_node query(int node, int beg, int ed, int i, int j)
{
    if(lazy[node]) relax(node, beg, ed);
    if(beg > j || ed < i) {
        _node dummy;
        return dummy;
    }
    if(beg >= i && ed <= j) return segtree[node];

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    _node p = query(lft, beg, mid, i, j);
    _node q = query(rgh, mid + 1, ed, i, j);
    _node res;
    Merge(res, p, q);
    return res;

}

int main()
{


    return 0;
}

