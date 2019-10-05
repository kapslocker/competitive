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

const int mod = 1e9 + 7;

int modpow(int x, int n) {
    if(n == 1)
        return x;
    if(n == 0)
        return 1;
    int temp = modpow((x * x) % mod, n / 2);
    if(n % 2 == 0)
        return temp;
    return (x * temp) % mod;
}

int solve(int n, int p) {
    // prod g(i, p) i = 1,2...n
    int ans = 1, curr = p;
    for(int pow = 1; ;pow++) {
        int total = n / curr;
        int largerMultiples = (n / curr) / p;
        int contribution = total - largerMultiples;
        int cp = curr % mod;
        ans *= modpow(cp, contribution);
        if(total == 0)
            break;
        if(curr > LLONG_MAX / p)
            break;
        curr *= p;
        ans %= mod;
    }
    return ans % mod;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, n;
    cin >> x >> n;

    vector<int> primes;
    int k = sqrt(x);
    for(int i = 2; i <= k; i++) {
        if(x % i == 0) {
            primes.push_back(i);
            while(x % i == 0) {
                x = x / i;
            }
        }
    }
    if(x > 1)
        primes.push_back(x);
    int ans = 1;
    for(int& p : primes) {
        ans *= solve(n, p);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
