#include<bits/stdc++.h>
using namespace std;

int fnc(int pos)
{
    return ara[pos];
}

int main()
{
    int n;
    int ara[15];
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> ara[i];
    }
    int val;
    cin >> val;

    int lo = 1, hi = n;

    while(lo < hi){

        int mid = (lo + hi) / 2;
        if(fnc(mid) < val) lo = mid + 1;
        else hi = mid;
    }

    cout << lo << ' ' << ara[lo] << endl;

    return 0;
}

/*

12
2 3 5 6 7 9 9 9 9 10 10 10
9

*/
