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


vector<int> primes;

vector<int> ss(100000, 1);

void sieve() {
    ss[0] = 0; ss[1]= 0;
    for(int i = 2; i < 100000; i++) {
        if(ss[i]) {
            for(int j = i * i; j < 100000; j += i) {
                ss[j] = false;
            }
        }
    }
    for(int i = 0; i < 100000; i++) {
        if(s[i])
            primes.push_back(i);
    }
}

string maximize(int n, int e) {
    if(n >= 7919) {
        return string(n - e, 'a' + 25);
    }
    sieve();
    string s;
    for(int i = 0; i < n; i++) {
        s[i] = 'a' + (primes[i] % 26);
    }
    while(e > 0) {
        for(int i = 1; i < n; i++) {
            if(s[i] > s[i-1]) {
                s[i-1] = '.';
                e--;
            }
        }
        if(e > 0) {
            for(int i = n - 1; i >= 0; i--) {
                if(e == 0)
                    break;
                if(s[i] != '.') {
                    s[i] = '.';
                    e--;
                }
            }
        }
    }    
    string ans;
    for(int i = 0; i < n; i++) {
        if(s[i] !='.') {
            ans += s[i];
        }
    }
    return ans;
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    maximize(100, 0);
    return 0;
}
