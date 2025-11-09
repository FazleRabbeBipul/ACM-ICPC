#include<bits/stdc++.h>
using namespace std;
int n, w;
int wt[500], prc[500];
int dp[500][5000];
int fnc(int pos, int weightLeft)
{
    if(pos == n + 1) return 0;
    if(weightLeft == 0) return 0;
    if(dp[pos][weightLeft] != -1) return dp[pos][weightLeft];
    int p = 0;
    if(weightLeft - wt[pos] >= 0) p = fnc(pos + 1, weightLeft - wt[pos]) + prc[pos];
    int q = fnc(pos + 1, weightLeft);

    return dp[pos][weightLeft] = max(p, q);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &wt[i], &prc[i]);
    }

    cin >> w;

    int ans = fnc(1, w);
    cout << ans << endl;

    int curPos = 1, curWeightleft = w;

    while(true){
        if(curPos == n + 1) break;
        int p = 0;
        if(curWeightleft - wt[curPos] >= 0) p = dp[curPos + 1][curWeightleft - wt[curPos]];
        int q = dp[curPos + 1][curWeightleft];

        if(p >= q) {
            cout << curPos << ' ';
            int ncurpos = curPos + 1;
            int ncurweightleft = curWeightleft - wt[curPos];

            curPos = ncurpos;
            curWeightleft = ncurweightleft;
        }
        else{
            curPos++;
        }

    }

    return 0;
}
