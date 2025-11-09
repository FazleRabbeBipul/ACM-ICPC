#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define show(x) cout << #x << " : " << x << endl

template <class T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag,
         tree_order_statistics_node_update>;
// indexed_set<ll> st;st.order_of_key(x);

const long long mod = 1e9 + 7;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

#define ys cout << "YES" << endl
#define no cout << "NO" << endl

void build(ll ind, ll low, ll high, vector<ll> &v, vector<ll> &segTree)
{
    if (low == high)
    {
        segTree[ind] = v[low];
        return;
    }

    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, v, segTree);
    build(2 * ind + 2, mid + 1, high, v, segTree);

    segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
}

// (l-r) range increase value with val.
void rangeUpdate(ll ind, ll low, ll high, ll l, ll r, ll val, vector<ll> &v, vector<ll> &segTree, vector<ll> &lazy)
{
    if (lazy[ind] != 0) /// if any pending lazy update do it first
    {
        segTree[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (low > r || high < l)
    { /// completely outside
        return;
    }

    if (low >= l && high <= r)
    {
        /// add value for low-> high
        segTree[ind] += (high - low + 1) * val;

        if (low != high)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }

    ll mid = (low + high) / 2;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val, v, segTree, lazy);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val, v, segTree, lazy);

    segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
}

// (l, r) range sum of the values.
ll querySum(ll ind, ll low, ll high, ll l, ll r, vector<ll> &segTree, vector<ll> &lazy)
{
    if (lazy[ind] != 0)
    {
        segTree[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (low > r || high < l)
        return 0;

    if (low >= l && high <= r)
        return segTree[ind];

    ll mid = (low + high) / 2;
    ll left = querySum(2 * ind + 1, low, mid, l, r, segTree, lazy);
    ll right = querySum(2 * ind + 2, mid + 1, high, l, r, segTree, lazy);

    return left + right;
}

void solve(int tc)
{
    ll n;
    cin >> n;

    vector<ll> v(n), segTree(4 * n), lazy(4 * n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    build(0, 0, n - 1, v, segTree);

    ll q;
    cin >> q;

    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            rangeUpdate(0, 0, n - 1, l - 1, r - 1, val, v, segTree, lazy);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll sum = querySum(0, 0, n - 1, l - 1, r - 1, segTree, lazy);

            cout << sum << endl;
        }
    }
}

int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
        solve(i);
}
