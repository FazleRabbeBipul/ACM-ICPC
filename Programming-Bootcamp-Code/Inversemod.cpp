#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll bigMod(ll n, ll r)
{
    if(r == 0) return 1;
    ll re = bigMod(n, r/2);
    re = (re * re) % mod;
    if(r % 2) re = (re * n) % mod;
    return re;
}
ll invMod(ll n)
{
    return bigMod(n, mod - 2);
}


ll fct[400000], inv[400000];
ll nCr(ll n, ll r)
{
    if(n < r) return 0;
    ll re1 = fct[n];
    re1 = (re1 * inv[r]) % mod;
    re1 = (re1 * inv[n - r]) % mod;
    return re1;
}
int main()
{
    fct[0] = inv[0] = 1;
    for(ll i = 1; i <= 100000; i++){
        fct[i] = (fct[i - 1] * i) % mod;
        inv[i] = invMod(fct[i]);
    }



    return 0;
}
