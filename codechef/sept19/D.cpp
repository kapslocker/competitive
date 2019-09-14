#include <bits/stdc++.h>
using namespace std;

#define int long long


int solve(int n, int m) {
    int low = n - 1, high = (n * (n + 1)) / 2;
    if(m < low || m > high) {
        return -1;
    }
    else if(n == 1) {
        if(m == 0)
            return 0;
        return 1;
    }
    else if(n == 2) {
        if(m == 1) {
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(n - 1 <= m && m <= n + 1) {
        return 2;
    }
    else if(n + 2 <= m && m <= 2 * n) {
        return 3;
    }
    else {
        int alpha = (2 * m) % n;
        if(alpha == 0)
            alpha = n;
        return (2 * m - alpha) / n;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    // for(int i = 1; i < 10; i++) {
    //     for(int j = i-1; j < 60; j++) {
    //         cout << i << " " << j;
    //         int ans = solve(i, j);
    //         cout << " " << ans << endl;
    //         if(ans == -1)
    //             break;
    //     }
    // }
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}
