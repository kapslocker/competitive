#include <bits/stdc++.h>
using namespace std;

#define int long long


template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream &os, set<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class K, class X> ostream &operator<<(ostream& os, map<K,X> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

bool solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<bool> pre(n, false), suf(n, false);
    pre[0] = true;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] & (arr[i] >= i);
    }

    suf[n-1] = true;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i+1] & (arr[i] >= n-1-i);
    }

    for(int i = 0; i < n; i++) {
        if (pre[i] && suf[i]) {
            return true;
        }
    }

    return false;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        bool ans = solve();
        if (ans) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}