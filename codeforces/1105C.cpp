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

const int mod = 1000000007;

int f1(int l) {
    // 3k
    int a = (l - 1) / 3;
    return a;
}

int f2(int l) {
    // 3k + 1
    int a = (l + 1) / 3;
    return a;
}

int f3(int l) {
    // 3k + 2
    int a = (l) / 3;
    return a;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int> > dp(n, vector<int>(3, 1));
    int a = f1(r + 1) - f1(l);
    int b = f2(r + 1) - f2(l);
    int c = f3(r + 1) - f3(l);
    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;
    for(int i = 1; i < n; i++) {
        dp[i][0] = ((dp[i - 1][0] * a) % mod + (dp[i - 1][1] * c) % mod + (dp[i - 1][2] * b) % mod) % mod;
        dp[i][1] = ((dp[i - 1][0] * b) % mod + (dp[i - 1][1] * a) % mod + (dp[i - 1][2] * c) % mod) % mod;
        dp[i][2] = ((dp[i - 1][0] * c) % mod + (dp[i - 1][1] * b) % mod + (dp[i - 1][2] * a) % mod) % mod;
    }
    cout << dp[n - 1][0] << endl;
    return 0;
}
