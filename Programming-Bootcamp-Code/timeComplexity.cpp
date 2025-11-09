#include <bits/stdc++.h>

using namespace std;
O(n)

int main(){

///    int n = 100000000, sum = 0;
///O(n)
///    scanf("%d", &n);
///    for(int i = 1; i <= n; i++) sum += i;
    ///printf("%d", 2 * n);

    ///O(1)
///    int n = 2, m = 3;
///    int x = n + m;
///    int y = x * 2;
///    int z = x + y;
///    z = z * z;

//    int n;
//    cin >> n;
//    int sum = 0;
//    for(int i = 1; i <= n; i++){
//
//        for(int j = 1; j <= n; j++){
//            sum += i * j;
//        }
//
//    }
//    n + n + n ... + n = n * n = n^2
//    O(n^2)

//    int sum = 0;
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            sum += i * j;
//        }
//
//        for(int j = 1; j <= m; j++){
//            sum += i * j;
//        }
//    }
//    O(n^2 + n*m)

//    O(n^3 + n^2*m + m^2)
//    O(n^3 + n^2*m + n^2*m^2 + m^3)
//
//    O(n^3 + n^2*m^2)

//    int sum = 0;
//    for(int i = 1; i <= n; i++){
//        for(int j = i; j <= n; j++) sum += i * j;
//    }
//
//    n + (n - 1) + (n - 2 ) + ... + 1
//    n * (n + 1)

      ///O(n+m)
//    i = 1 -> 21
//    i = 22 -> 42
//    i = 43 -> 63
//    for(int i = 1; i <= n; i++){
//
//        int j = i, cc = 0;
//        while(j <= n && cc <= m) j++, cc++;
//        i = j;
//    }

    int stp = 0;
    while(n){
        n = n / 2;
        stp++;
    }

    100 -> 50 -> 25 -> 12 -> 6 -> 3 -> 1 -> 0
    2^stp = n
    stp = log_2(n)

    a^x = b, x =log_a(b)
    return 0;
}

