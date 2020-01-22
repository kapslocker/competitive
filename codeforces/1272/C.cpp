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

int MAX = 5000;
vector<int> s(MAX, 1);
vector<int> primes;
void sieve() {
    s[1] = 0;
    s[0] = 0;
    for(int i = 2; i < MAX; i++) {
        if(!s[i])
            continue;
        for(int j = i*i; j < MAX; j += i) {
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
    int r, c;
    cin >> r >> c;
    if(r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }
    sieve();
    if(r == 1) {
        for(int i = 0; i < c; i++) {
            cout << primes[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(c == 1) {
        for(int i = 0; i < r; i++) {
            cout << primes[i] << endl;
        }
        return 0;
    }
    set<int> rowg;
    for(int i = 0; i < r; i++) {
        rowg.insert(primes[i]);
    }
    set<int> colg = rowg;
    for(int x : rowg) {
        for(int y : rowg) {
            colg.insert(x * y);
        }
    }
    for(int x : rowg) {
        colg.erase(x);
    }
    colg.insert(1);
    vector<int> rg(rowg.begin(), rowg.end()), cg(colg.begin(), colg.end());
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << rg[i] * cg[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
