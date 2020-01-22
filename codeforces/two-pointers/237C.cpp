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

const int MAX = 1e6 + 1;
vector<int> primes;
vector<int> s(MAX, 1);
void sieve() {
    s[0] = 0;
    s[1] = 0;
    for(int i = 2; i < 10000; i++) {
        if(!s[i])
            continue;
        for(int j = i * i; j < MAX; j += i) {
            s[j] = 0;
        }
    }
    for(int i = 0; i < MAX; i++) {
        if(s[i])
            primes.push_back(i);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int a, b, k;
    cin >> a >> b >> k;
    int l = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
    int r = lower_bound(primes.begin(), primes.end(), b) - primes.begin();
    debug(l, r);
    if(r - l < k) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = l; i <= r - k + 1; i++) {
        ans = max(ans, primes[i + k - 1] - primes[i]);
    }
    cout << ans + 1 << endl;
    return 0;
}
