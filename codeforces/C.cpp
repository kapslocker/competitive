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
    int n, MAX = 1024 * 1024 + 10, ans = 0;
    cin >> n;
    vector<int> odds(MAX, 0), evens(MAX, 0), arr(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++) {
        arr[i] = arr[i] ^ arr[i - 1];
    }
    for(int l = n; l >= 1; l--) {
        if(l % 2 == 0) {
            ans += odds[arr[l-1]];
            evens[arr[l]]++;
        }
        else {
            ans += evens[arr[l-1]];
            odds[arr[l]]++;
        }
    }
    cout << ans << endl;
    return 0;
}
