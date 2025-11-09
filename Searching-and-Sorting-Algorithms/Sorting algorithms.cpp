#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const long long mod = 1e9 + 7;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
const long long maxN = 2e5 + 5;

class macro
{
public:
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long int, long long int>
    template <class T> // indexed_set<ll> st;  st.order_of_key(x);
    using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ys cout << "YES" << endl
#define no cout << "NO" << endl
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define show(x) cout << #x << " : " << x << endl
};

class Solution
{
public:
    void solve(int tc)
    {
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    Solution Obj;

    for (int i = 1; i <= tc; i++)
        Obj.solve(i);
}