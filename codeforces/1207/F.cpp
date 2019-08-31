#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int N = 500000;

int d = sqrt(N);

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q, t, x, y;
    cin >> q;
    vector<vector<int> > ans(d, vector<int>(d, 0));
    vector<int> a(N+1, 0);
    while(q--) {
        cin >> t >> x >> y;
        if(t == 1) {
            a[x] += y;
            for(int n = 1; n < d; n++) {
                ans[n][x % n] += y;
            }
        }
        else {
            if(x < d) {
                cout << ans[x][y] << endl;
            }
            else {
                int s = 0;
                for(int i = y; i <= N; i+=x)
                    s += a[i];
                cout << s << endl;
            }
        }
    }
    return 0;
}
