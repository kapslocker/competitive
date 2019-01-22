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

int MAXN = 10000000;
unordered_set<int> primes;
vector<int> pcount(MAXN, 0);

void sieve() {
    vector<int> seen(MAXN, 0);
    for(int i = 2; i < MAXN; i++) {
        if(seen[i])
            continue;
        primes.insert(i);
        for(int j = i * i; j < MAXN; j += i) {
            seen[j] = 1;
        }
    }
    return;
}


void solvex(int x) {
    for(auto &p : primes) {
        if(x == 1)
            return;
        if(x % p == 0) {
            pcount[p]++;
        }
        while(x % p == 0) {
            x = x / p;
        }
    }
    return;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, x;
    cin >> n;
    sieve();
    for(int i = 0; i < n; i++) {
        cin >> x;
        solvex(x);
    }
    vector<int> fpre(MAXN, 0);
    for(int i = 1; i < MAXN; i++) {
        fpre[i] = fpre[i - 1] + pcount[i];
    }
    cout << "done\n";
    int l, r;
    cin >> m;
    for(int i = 0; i < m; i++ ) {
        cin >> l >> r;
        if(l >= MAXN) {
            cout << 0 << endl;
        }
        else
        cout << fpre[min(r, MAXN)] - fpre[l - 1] << endl;
    }
    return 0;
}
