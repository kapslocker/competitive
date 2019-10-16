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



// segtree
const int N = 1e5 + 1;
int n;
int t[26][2 * N];

void build(int c) {
    for(int i = n - 1; i > 0; --i) {
        t[c][i] = (t[c][i<<1] | t[c][i<<1|1]);
    }
}

void modify(int c, int pos, int value) {
    for(t[c][pos += n] = value; pos > 1; pos >>= 1) {
        t[c][pos >> 1] = t[c][pos] | t[c][pos ^ 1];
    }   
}

int query(int c, int l, int r) {  // sum on interval [l, r) for char c
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res |= t[c][l++];
    if (r&1) res |= t[c][--r];
  }
  return res;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = s.length();
    vector<int> arr(n);
    int q;
    cin >> q;
    for(int i = 0; i < n; i++) {
        char ch = s[i];
        t[ch - 'a'][n + i] = 1;
    }
    for(int i = 0; i < 26; i++) {
        build(i);
    }
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            string cc;
            cin >> cc;
            char c = cc[0];
            char next = (char) c;
            char prev = s[b-1];
            s[b-1] = next;
            modify(prev - 'a', b - 1, 0);
            modify(next - 'a', b - 1, 1);
        }
        else {
            b--;
            int c;
            cin >> c;
            int ans = 0;
            for(int ii = 0; ii < 26; ii++) {
                ans += query(ii, b, c);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
