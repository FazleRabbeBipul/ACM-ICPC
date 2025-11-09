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

/*
    Linear Search O(n)
    Sentinel Linear Search
    Binary Search
    Meta Binary Search | One-Sided Binary Search
    Ternary Search
    Jump Search
    Interpolation Search
    Exponential Search
    Fibonacci Search
    The Ubiquitous Binary Search
*/

class LinearSearch_
{
public:
    ll LinearSearch(ll x, ll n, vector<ll> &vec)
    {
        // goes through each element of a list until the desired element is found
        // Complexity O(N)
        for (int i = 0; i < n; i++)
        {
            if (x == vec[i])
                return i;
        }

        return -1; // not found;
    }
};

class SentinelLinearSearch_
{
public:
    void SentinelLinearSearch(ll key, ll n, vector<ll> &vec)
    {
        // we can avoid the conditional check for the end of the array in the loop
        // and terminate the search early , Complexity O(N)

        ll last = vec[n - 1];
        vec[n - 1] = key;

        ll i = 0;
        while (vec[i] != key)
        {
            i++;
        }

        if ((i < n - 1) || (vec[n - 1] == key))
            cout << key << " is present at index " << i;
        else
            cout << "Element Not found";
    }
};

class BinarySearch_
{
public:
    // Divide the search space into two halves finding ,by finding the middle index “mid”
    // Method: iterative method, recursive method
    // Complexity O(log N), The array should be sorted.

    ll BinarySearch1(ll l, ll r, ll x, vector<ll> &vec)
    {
        // iterative method
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;

            if (vec[mid] == x)
                return mid;

            if (vec[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    ll BinarySearch2(ll l, ll r, ll x, vector<ll> &vec)
    {
        // recursive method
        if (l <= r)
        {
            ll mid = l + (r - l) / 2;

            if (vec[mid] == x)
                return mid;

            if (vec[mid] < x)
                BinarySearch2(mid + 1, r, x, vec);
            else
                BinarySearch2(l, mid - 1, x, vec);
        }

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}