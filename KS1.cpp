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

void debug_out() {  cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0, pre = 0;
        cin >> n;
        vector<int> arr(n + 1);
        for(int i = 1; i <= n; i++) {
          cin >> arr[i];
        }
        map<int, pair<int, int> > hmap;
        // hmap[x] -> indices j s.t. xor[0..j] = x
        hmap[0].first = 1;
        hmap[0].second = 0;
        for(int k = 1; k <= n; k++) {
            pre = pre ^ arr[k];
            int m = hmap[pre].first, s = hmap[pre].second;
            ans += m * k - s - m;
            // debug(k, m*k - s - m);
            hmap[pre].first++;
            hmap[pre].second += k;
        }
        cout << ans << endl;
    }
    return 0;
}
