#include<bits/stdc++.h>
using namespace std;
int coins[100], koybar[100];
int n, val;

int fnc(int pos, int val)
{
    if(pos == n + 1) {
         if(val == 0) return 1;
        else return 0;
    }

    if(dp[pos][val] != -1) return dp[pos][val];

    int res1 = 0;

//    for(int i = 1; i <= koybar[pos]; i++){
//        int valbaki = val - i * coins[pos];
//        if(valbaki >= 0) res1 = res1 + fnc(pos + 1, valbaki);
//    }
    if(val - coins[pos] >= 0) res1 = fnc(pos, val - coins[pos]);
    int res2 = fnc(pos + 1, val);

    return dp[pos][val] = (res1 + res2);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> coins[i];

    cin >> val;

    return 0;
}
