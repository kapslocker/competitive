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

int modpow(int x, int n, int mod) {
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return modpow((x * x) % mod, n / 2, mod);
    return (x * modpow((x * x) % mod, n / 2, mod)) % mod;
}

int32_t main() {
    int w, h, mod = 998244353;
    cin >> w >> h;
    cout << (4 * modpow(2, w + h - 2, mod) % mod) << endl;
    return 0;
}