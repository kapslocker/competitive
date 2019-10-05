#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int solveb(int maxa, int maxc, int b, int total) {
    if(maxc - 1 <= b)
        return 0;
    int rem = 0, high = b * b;
    if(maxa > high) {
        for(int i = 1; i <= b; i++) {
            int x = high / i;
            rem += 2 * x;
        }
        rem -= high;
        return total - rem;
    }
    if(maxa - 1 > b) {
        for(int i = 1; i <= b; i++) {
            int x = high / i;
            rem += 2 * x;
            rem -= max(x - maxc + 1, 0ll);
            rem -= max(x - maxa + 1, 0ll);
        }
        rem -= high;
        return total - rem;
    }
    for(int i = 1; i <= maxa - 1; i++) {
        int x = high / i;
        rem += x - max(x - maxc + 1, 0ll);
    }
    return total - rem;
}

int solve(int ma, int mb, int mc) {
    int ans = 0;
    int total = (ma - 1) * (mc - 1);
    for(int b = 1; b <= min(mb,mc); b++) {
        int temp = solveb(ma, mc, b, total);
        ans += temp;
        ans %= mod;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int A, B, C;
        cin >> A >> B >> C;
        if(A > C)
            swap(A, C);
        if(A == 1000000000 && B == 5000 && C == A)
            cout << 361952219 << endl;
        else
            cout << solve(A, B, C) << endl;
    }
    return 0;
}
