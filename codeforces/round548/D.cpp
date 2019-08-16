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

const int mod = 1e9+7;

int modpow(int n, int p) {
    if(p == 1)
        return n;
    if(p == 0)
        return 1;
    if(p % 2 == 0) {
        return modpow((n * n) % mod, p / 2);
    }
    return (n * modpow((n * n) % mod, p / 2)) % mod;
}


int modinv(int x) {
    return modpow(x, mod - 2);
}

int MAX;
map<int, int> primes;
void sieve() {
    vector<int> visited(MAX + 1, 0);
    for(int i = 2; i * i <= MAX; i++) {
        if(visited[i] < 0)
            continue;
        visited[i] = 1;
        for(int j = i + i; j <= MAX; j += i) {
            if(visited[j] == 0) {
                visited[i]++;
                visited[j]--;
            }
        }
    }
    for(int i = 2; i <= MAX; i++) {
        if(visited[i] > 0)
            primes[i] = visited[i];
        if(visited[i] == 0)
            primes[i] = 1;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> m;
    MAX = m;
    int tot = 0;
    sieve();
    if(m == 1) {
        cout << 1 << endl;
        return 0;
    }
    for(auto &x : primes) {
        int s = x.second, term;
        term = modinv(m - s);
        debug(term);
        tot += (m * modinv(m - s)) % mod;
        tot = tot % mod;
    }
    cout << tot << endl;
    return 0;
}
