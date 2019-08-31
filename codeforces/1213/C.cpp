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


int cycle(int n) {
    int d = n % 10;
    switch(d) {
        case 0: return 0;
        case 1: return 45;
        case 2: return 20;
        case 3: return 45;
        case 4: return 20;
        case 5: return 5;
        case 6: return 20;
        case 7: return 45;
        case 8: return 20;
        case 9: return 45;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    map<int, int> sizes;
    for(int i = 1; i <= 9; i++) {
        sizes[i] = (10 / gcd(i, 10));
    }
    sizes[0] = 1ll;
    vector<vector<int> > val(10);
    for(int i = 0; i < 10; i++) {
        for(int j = 1; j <= sizes[i]; j++) {
            val[i].push_back((i * j) % 10);
        }
    }
    while(t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        if(n < m) {
            cout << 0 << endl;
            continue;
        }
        int num_multiples = n / m;
        int d = m % 10;
        int num_complete_cycles = num_multiples / sizes[d];
        ans = ans + cycle(d) * num_complete_cycles;
        int remaining = num_multiples % sizes[d];
        for(int i = 0; i < remaining; i++) {
            ans = ans + val[d][i];
        }
        cout << ans << endl;
    }
    return 0;
}
