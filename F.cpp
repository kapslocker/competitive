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

const int MOD = 1e9 + 7, MAX = 1000001;

vector<int> fact(MAX);

int modinv(int n, int mod);
int modpow(int n, int p, int mod) {
    if(p == 1)
        return n;
    if(p == 0)
        return 1;
    if(p < 0) {
        return modinv(modpow(n, -p, mod), mod);
    }
    if(p % 2 == 0)
        return modpow((n * n) % mod, p / 2, mod);
    return (n * modpow((n * n) % mod, p / 2, mod)) % mod;
}

int modinv(int n, int mod) {
    return modpow(n, mod - 2, mod);
}

void fillfact() {
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

int solvek(int n, int m, int k) {
    int ans = 1;
    ans = (ans * fact[n - 2]) % MOD;
    ans = (ans * fact[m - 1]) % MOD;
    ans = (ans * modinv(fact[k - 1], MOD)) % MOD;
    ans = (ans * modinv(fact[n - 1 - k], MOD)) % MOD;
    ans = (ans * modinv(fact[m - k], MOD)) % MOD;
    ans = (ans * modpow(m, n - k - 1, MOD)) % MOD;
    ans = (ans * modpow(n, n - k - 2, MOD)) % MOD;
    ans = (ans * (k + 1)) % MOD;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b, ans = 0;
    cin >> n >> m >> a >> b;
    fillfact();
    for(int k = 1; k <= min(n - 1, m); k++) {
        ans += solvek(n, m, k);
        ans = ans % MOD;
    }
    cout << ans << endl;
    return 0;
}
