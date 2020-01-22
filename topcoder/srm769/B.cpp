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


vector<int> reconstruct(vector<int> top, vector<int> diag) {
    int n = top.size();
    vector<vector<int> > ans(n, vector<int>(n, 0));
    if(n == 1)
        return {top[0]};
    for(int i = 0; i < n; i++) {
        ans[0][i] = top[i];
    }
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += diag[i];
        ans[i][i] = diag[i];
    }
    for(int i = 1; i < n; i++) {
        ans[i][0] = ans[i-1][0] + ans[i][i] - ans[i-1][i];
        for(int j = 1; j < n; j++) {
            // find
            ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
        }
    }
    vector<int> x;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            x.push_back(ans[i][j]);
        }
    }
    return x;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return 0;
}
