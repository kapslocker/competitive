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

int maxn = 1e6;
vector<int> s(1e6 + 1, 1);
vector<int> primes;
void sieve() {
    s[0] = 0;
    s[1] = 0;
    for(int i = 2; i < maxn; i++) {
        if(!s[i])
            continue;
        primes.push_back(i);
        for(int j = i * i; j <= maxn; j += i) {
            s[j] = 0;
        }
    }
}


int num_factors(int g) {
    int count = 1;
    for(int i = 0; i < primes.size(); i++) {
        if(g % primes[i] == 0) {
            int c = 0;
            while(g % primes[i] == 0) {
                c++;
                g = g / primes[i];
            }
            count = count * (c + 1);
        }
        if(g == 1)
            break;
    }
    if(g > 1) {
        count = count * 2;
    }
    return count;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int g = arr[0];
    for(int i = 1; i < n; i++) {
        g = __gcd(g, arr[i]);
    }
    int count = num_factors(g);
    cout << count << endl;
    return 0;
}
