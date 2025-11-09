#include<bits/stdc++.h>
using namespace std;
const int maxn = 100009;
int ara[maxn];
int segtree[4 * maxn];
int lazy[4 * maxn];

void build(int node, int beg, int ed)
{
    if(beg == ed){
        segtree[node] = ara[beg];
        return;
    }

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    build(lft, beg, mid);
    build(rgh, mid + 1, ed);
    segtree[node] = segtree[lft] + segtree[rgh];a
}

void singleUpdate(int node, int beg, int ed, int i, int val)
{
    if(beg > i || ed < i) return;
    if(beg == ed) {
        segtree[node] += val;
        return;
    }

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    singleUpdate(lft, beg, mid, i, val);
    singleUpdate(rgh, mid + 1, ed, i, val);

    segtree[node] = segtree[lft] + segtree[rgh];

}
void relax(int node, int beg, int ed)
{
    segtree[node] += lazy[node] * (ed - beg + 1);
    int lft = 2 * node;
    int rgh = lft + 1;
    if(beg != ed){
        lazy[lft] += lazy[node];
        lazy[rgh] += lazy[node];
    }
    lazy[node] = 0;
}

void rangeUpdate(int node, int beg, int ed, int i, int j, int val)
{
    if(lazy[node]) relax(node, beg, ed);

    if(beg > j || ed < i) return;
    if(beg >= i && ed <= j){
        lazy[node] += val;
        return;
    }

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    rangeUpdate(lft, beg, mid, i, j, val);
    rangeUpdate(rgh, mid + 1, ed, i, j, val);

    segtree[node] = segtree[lft] + segtree[rgh];

}

int query(int node, int beg, int ed, int i, int j)
{
    if(lazy[node]) relax(node, beg, ed);
    if(beg > j || ed < i) return 0;
    if(beg >= i && ed <= j) return segtree[node];

    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgh = lft + 1;

    int p = query(lft, beg, mid, i, j);
    int q = query(rgh, mid + 1, ed, i, j);
    return (p+q);

}

int main()
{


    return 0;
}
