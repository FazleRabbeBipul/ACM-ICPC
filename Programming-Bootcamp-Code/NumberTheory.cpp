#include<bits/stdc++.h>
using namespace std;
int mmm = 1000003;
int isPrime[100000];

int main()
{
    /// 2 ^ 100 % mmm ??
    ///(a * b) % x = ((a % x) * (b % x))     % x

//    long long ans = 1;
//    for(int i = 1; i <= 100; i++) ans = ((ans % mmm) * (2 % mmm)) % mmm;
//
//    cout << ans % mmm << endl;

    ///Primality testing
    ///O(n) -> O(root(n)) ->
    int n = 10000;
    bool flg = true;
    int xx = sqrt(n);
    for(int i = 2; i <= xx; i++) {
        if(n % i == 0) flg = false;b
    }

    if(flg == true) cout << "Prime" << endl;
    else cout << "Not Prime" << endl;

    ///sieve

    for(int i = 1; i <= n; i++) isPrime[i] = 0;
    isPrime[1] = isPrime[0] = 1;

    for(int i = 2; i <= n; i++){

        if(isPrime[i] == 1) continue;

        for(int j = i; j <= n; j += i) isPrime[j] = 1;

    }

    return 0;
}
