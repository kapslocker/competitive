#include <bits/stdc++.h>
using namespace std;



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


int tot(int i, int j, int k) {
    return i * j + j * k + i * k;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, s, p;
    cin >> r >> s >> p;
    vector<vector<vector<double> > > dp(r + 1, vector<vector<double> >(s + 1,
                                                vector<double>(p + 1, 0.0)));
    for(int i = r; i >= 0; i--) {
        for(int j = s; j >= 0; j--) {
            for(int k = p; k >= 0; k--) {
                if(i == r && j == s && k == p) {
                    dp[i][j][k] = 1.0;
                    continue;
                }
                vector<double> pr(3, 0.0);
                if(tot(i + 1, j, k) > 0)
                    pr[0] = ((i + 1.0) * k) / tot(i + 1, j, k);
                if(tot(i, j + 1, k) > 0)
                    pr[1] = ((j + 1.0) * i) / tot(i, j + 1, k);
                if(tot(i, j, k + 1) > 0)
                    pr[2] = ((k + 1.0) * j) / tot(i, j, k + 1);
                if(i < r && k > 0)
                    dp[i][j][k] += pr[0] * dp[i + 1][j][k];
                if(j < s && i > 0)
                    dp[i][j][k] += pr[1] * dp[i][j + 1][k];
                if(k < p && j > 0)
                    dp[i][j][k] += pr[2] * dp[i][j][k + 1];
            }
        }
    }
    double p1 = 0.0, p2 = 0.0, p3 = 0.0;
    for(int i = 1; i <= r; i++) {
        p1 += dp[i][0][0];
    }
    for(int i = 1; i <= s; i++) {
        p2 += dp[0][i][0];
    }
    for(int i = 1; i <= p; i++) {
        p3 += dp[0][0][i];
    }
    cout << fixed << setprecision(10) << p1 << " " << p2 << " " << p3 << endl;
    return 0;
}
