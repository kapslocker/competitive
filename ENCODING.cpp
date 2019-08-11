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

vector<int> l,r;
//int l, r;


int vectoin(vector<int> &a, int start, int end) {
    // 1 indexed start, end
    int ans = 0, p = 1;
    for(int i = end; i >= start; i--) {
        ans = ans + p * a[i-1];
        p = 10 * p;
    }
    return ans;
}

int comp1(vector<int> &a) {
    int n = a.size();
    int ans = 0;    //TODO: Move to a vector.
    for(int d = 0; d < 10; d++) {
        for(int k = 1; k <= n; k++) {
            int po = pow(10, n - k);
            int t1 = vectoin(a, 1, k-1), t2 = vectoin(a, k+1, n);
            int c1 = (d < a[k-1]) * po * (1 + t1);
            int c2 = (d == a[k-1]) * (t1 * po + t2);
            int c3 = (d > a[k-1]) * t1 * po;
            int count = c1 + c2 + c3;
            ans = (ans + po * d * count) % mod;
        }
    }
    debug(ans);
    return ans;
}

int comp2(vector<int> &a) {
    int n = a.size(), ans = 0, t1, t2, c1, c2, c3, count;
    for(int d = 0; d < 10; d++) {
        for(int k = 2; k <= n; k++) {
            int po = pow(10, n - k);
            t1 = vectoin(a, 1, k-2);
            t2 = vectoin(a, k+1, n);
            c1 = (d < a[k-2]) * po * (t1 + 1);
            c2 = (d > a[k-2]) * (t1) * po;

            c3 = (d == a[k-2]) * (t1 * po + (d < a[k-1]) * po + (d == a[k-1]) * t2);
            count = c1 + c2 + c3;
            ans = (ans + po * d * count) % mod;
        }
    }
    debug(ans);
    return ans;
}

int solve() {
    int rterm = comp1(r) - comp2(r);
    debug(rterm);
    int lterm = comp1(l) - comp2(l);
    int ans = rterm - lterm;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int nl, nr;
        cin >> nl >> nr;
        l.resize(nl);
        r.resize(nr);
        for(int i = 0; i < nl; i++) {
            cin >> l[i];
        }
        for(int i = 0; i < nr; i++) {
            cin >> r[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
