#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <random>

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

// #define LOCAL 1

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

std::random_device rd; // obtain a random number from hardware
std::mt19937 eng(rd()); // seed the generator
std::uniform_int_distribution<> distr(2, 1e9); // define the range

int MAX_P = 100000;
vector<bool> is_prime(MAX_P + 1, true);
vector<int> primes;
void fill_sieve() {
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_P; i++) {
        if(is_prime[i] && i * i < MAX_P) {
            for(int j = i * i; j <= MAX_P; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= MAX_P; i++) {
        if(is_prime[i])
            primes.push_back(i);
    }
}

vector<int> factors(int n) {
    vector<int> ans;
    for(auto &p : primes) {
        if(n % p == 0) {
            ans.push_back(p);
            while(n % p == 0)
                n = n / p;
        }
        if(n == 1)
            break;
    }
    if(n > 1)
        ans.push_back(n);
    return ans;
}

int local_p;

int query(int x) {
    #ifdef LOCAL
    return (x * x) % local_p;
    #else
    int ans;
    cout << 1 << " " << x << endl << flush;
    cin >> ans;
    return ans;
    #endif
}


bool print(int ans) {
    #ifdef LOCAL
    cout << "SUCCESS: " << (ans == local_p) << endl;
    return ans == local_p;
    #else
    string resp;
    cout << 2 << " " << ans << endl << flush;
    cin >> resp;
    if(resp == "Yes")   return true;
    return false;
    #endif
}

int step(vector<int> &candidates) {
    int x, q, rem;
    while(1) {
        bool is_valid = true;
        x = distr(eng);
        debug("try", x);
        q = x * x;
        map<int, bool> seen;
        for(int p : candidates) {
            rem = q % p;
            if(seen[rem])
                is_valid = false;
            seen[rem] = true;
        }
        if(is_valid) {
            return x;
        }
    }
}

void solve() {
    int x1 = 65537, a = query(x1), x2;
    int val = abs(x1 * x1 - a);
    bool resp;
    vector<int> candidates = factors(val);
    debug(x1, a, val, candidates);
    if(candidates.size() == 1) {
        resp = print(candidates[0]);
        if(!resp) {
            exit(0);
        }
        return;
    }
    x2 = step(candidates);
    debug(x2);
    a = query(x2);
    for(int p : candidates) {
        if((x2 * x2) % p == a) {
            debug("ans:", p);
            resp = print(p);
            if(!resp)
                exit(0);
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    fill_sieve();
    int t;
    cin >> t;
    while(t--) {
        #ifdef LOCAL
        cin >> local_p;
        #endif
        solve();
    }
    return 0;
}