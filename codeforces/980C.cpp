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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    int g, right;
    set<int> start;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> label(256, -1);
    vector<int> ans;
    for(int it = 0; it < n; it++) {
        int c = p[it];
        if(label[c] > -1) {
            ans.push_back(label[c]);
            continue;
        }
        right = max(0, c - k + 1);
        int idx;
        for(idx = c; idx >= right; idx--) {
            if(label[idx] > -1)
                break;
        }
        if(idx < right) {
            // none colored
            for(int i = c; i > idx; i--)
                label[i] = right;
            ans.push_back(label[c]);
            continue;
        }
        g = label[idx];
        if(c - g < k) {
            for(int i = c; i >= g; i--)
                label[i] = g;
        }
        else {
            for(int i = c; i > idx; i--)
                label[i] = idx + 1;
        }
        ans.push_back(label[c]);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
