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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pre(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        pre[0] = arr[0];
        if(i > 0)
            pre[i] = pre[i - 1] + arr[i];
    }
    int sz, ans = 0;
    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            int lval = 0;
            if(l > 0)
                lval = pre[l - 1];
            int curr = (r - l + 1) * (pre[r] - lval);
            if(curr > ans) {
                debug(curr, l, r);
                sz = (r - l + 1);
                ans = curr;
            }
        }
    }
    cout << ans << " " << sz << endl;
    return 0;
}
