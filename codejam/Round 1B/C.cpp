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

int maxval(vector<int> &arr, int l, int r) {
    int ans = INT_MIN;
    for(int i = l; i <= r; i++) {
        ans = max(ans, arr[i]);
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int j = 0; j < t; j++) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n), d(n);
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> d[i];
        }
        int ans = 0;
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                int a = maxval(c, l, r), b = maxval(d, l, r);
                if(abs(a - b) <= k) ans++;
            }
        }
        cout << "Case #" << j + 1 << ": " << ans << endl;
    }
    return 0;
}
