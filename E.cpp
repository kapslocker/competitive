#include <bits/stdc++.h>
using namespace std;

// #define int long long


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


int solve(int wt, vector<int> &s, int idx) {
    if(idx == s.size())
        return 0;
    if(wt == 0 || wt > s[idx])
        return 0;
    if(wt % 2 != 0)
        return wt;
    int b = solve(wt / 2, s, idx + 1);
    return wt + b;
}

int32_t main() {
    int n, a;
    scanf("%d", &n);
    vector<int> mset;
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        freq[a]++;
    }
    for(auto &v : freq)
        mset.push_back(v.second);
    sort(mset.begin(), mset.end(), greater<int>());
    int ans = 0;
    for(int i = 1; i <= mset[0]; i++) {
        ans = max(ans, solve(i, mset, 0));
    }
    printf("%d\n", ans);
    return 0;
}
