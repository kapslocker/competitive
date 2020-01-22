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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += 2 * arr[i].first;
        }
        if(n == 2) {
            cout << -1 << endl;
            continue;
        }
        if(m < n) {
            cout << -1 << endl;
            continue;
        }
        int rem = m - n;
        ans += rem  * (arr[0].first + arr[1].first);
        cout << ans << endl;
        for(int i = 0; i < n - 1; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
        cout << n << " " << 1 << endl;
        for(int i = n; i < m; i++) {
            cout << arr[0].second << " " << arr[1].second << endl;
        }
    }
    return 0;
}
