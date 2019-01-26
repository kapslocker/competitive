#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isx(int x, int y) {
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    char input;
    cin>> input;
    return input == 'x';
}
void print(int ans) {
    cout << "! " << ans << endl;
    fflush(stdout);
}
void solve() {
    int low = 1, high = 2;
    while(!isx(low, high)) {
        low *= 2;
        high *= 2;
    }
    if(low == 1) {
        if(isx(2, 3)) {
            print(1);
            return;
        }
        else {
            print(2);
            return;
        }
    }
    int mid;
    while(high - low > 1) {
        mid = (low + high) / 2;
        if(isx(low, mid))
            high = mid;
        else
            low = mid;
    }
    print(high);
}

int32_t main() {
    string input;
    cin >> input;
    while(input != "end") {
        solve();
        cin >> input;
    }

    return 0;
}
