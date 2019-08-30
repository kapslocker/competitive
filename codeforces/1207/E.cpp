#include <bits/stdc++.h>
using namespace std;

int last_n(int num) {
   return num & ((1L<<7)-1);
}

void print(vector<int> &x) {
    cout << "? ";
    for(int i = 0; i < 100; i++) {
        cout << x[i] << " ";
    }
    cout << endl << flush;
}

int resp(vector<int> &arr) {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int left, right, ans;
    vector<int> q1(100), q2(100);
    for(int i = 1; i <= 100; i++) {
        q1[i-1] = i;
    }
    print(q1);
    left = resp(q1);

    for(int i = 1; i <= 100; i++) {
        int q = (i << 7);
        q2[i-1] = q;
    }
    print(q2);
    right = resp(q2);
    ans = ((left >> 7) << 7) + last_n(right);
    cout << "! " << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
