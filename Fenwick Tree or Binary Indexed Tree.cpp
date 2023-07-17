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

// Using O(logn) fenwick tree/ Binary Indexed tree
// (l, r) range sum and increase ind by value val.

void update(ll i, ll add, ll n, vector<ll> &bit)
{
    while (i <= n)
    {
        bit[i] += add;
        i += (i & (-i));
    }
}

ll sum(ll i, vector<ll> &bit)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}

void solve(int tc)
{
    // cout << "Case " << tc << ": ";
    ll n;
    cin >> n;

    vector<ll> v(n + 1), bit(n + 5, 0);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    /// Generate Fenwick Tree/ Binary indexed tree with given array V.
    for (int i = 1; i <= n; i++)
        update(i, v[i], n, bit);

    ll q;
    cin >> q;
    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll ind, val;
            cin >> ind >> val;
            update(ind, val, n, bit); // increase ind by value val.
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll ans = sum(r, bit) - sum(l - 1, bit); // sum of values (l, r)

            cout << ans << endl;
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
