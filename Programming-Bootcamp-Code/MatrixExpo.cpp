#include<bits/stdc++.h>
using namespace std;
struct Mat{
    ll row, col;
    ll m[10][10];
    Mat(){
        row = col = 0;
        memset(m, 0, sizeof(m));
    }
    Mat(int r, int c)
    {
        row = r, col = c;
        memset(m, 0, sizeof(m));
    }
};


Mat mult(Mat a, Mat b)
{
    Mat c;
    if(a.col != b.row){
        assert(false);
    }

    for(int i = 1; i <= a.row; i++){
        for(int j = 1; j <= b.col; j++){
            for(int k = 1; k <= b.row; k++){
                ll re = (a.m[i][k] * b.m[k][j]) % mod;
                c.m[i][j] += re;
                c.m[i][j] = c.m[i][j] % mod;
            }

        }

    }
}

Mat bigMod(Mat a, r)
{
    if(r == 0) {
        Mat Identity(a.row, a.col);
        for(int i = 1; i <= a.row; i++) Identity.m[i][j] = 1;
        return Identity;
    }

    Mat x = bigMod(a, r/2);
    Mat y = mult(x, x);
    if(r % 2) y = mult(y, a);
    return y;
}

int main()
{
    int n;
    cin >> n;

    if(n < 2) cout << n + 1 << endl;
    else{
        Mat mat(3, 3);
        mat.m[1][1] = mat.m[1][2] = mat.m[1][3] = 1;
        mat.m[2][2] = mat.m[2][3] = 1;
        mat.m[3][2] = 1;

        Mat mat2 = bigMod(mat, n - 1);

        ll ans = mat2.m[ 1][1] * 2 + mat2.m[1][2] + mat2.m[1][3];

    }


    return 0;
}
