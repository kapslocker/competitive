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

void east(string &path) {
    // find first row with 0 right turns
    int pr = 1, pc = 1, cr = 1, cc = 1, n = path.length();
    for(int i = 0; i < n; i++) {
        if(path[i] == 'E') {
            cr = pr;
            cc = pc + 1;
        }
        else {
            if(i == 0 || path[i - 1] == 'S')
                break;
            cc = pc;
            cr = pr + 1;
        }
        pr = cr;
        pc = cc;
    }
    string ans(n, '0');
    pc = cc; pr = cr;
    cc = n / 2 + 1; cr = n / 2 + 1;
    int i = n - 1;
    while(cr != pr) {
        ans[i--] = 'S';
        cr--;
    }
    while(cc != 1) {
        ans[i--] = 'E';
        cc--;
    }
    while(cr != 1) {
        ans[i--] = 'S';
        cr--;
    }
    cout << ans << endl;
}

void south(string &path) {
    int pr = 1, pc = 1, cr = 1, cc = 1, n = path.length();
    // find first column with 0 south
    for(int i = 0; i < n; i++) {
        if(path[i] == 'S') {
            cc = pc;
            cr = pr + 1;
        }
        else {
            if(i == 0 || path[i - 1] == 'E')
                break;
            cc = pc + 1;
            cr = pr;
        }
        pr = cr;
        pc = cc;
    }
    string ans(n, '0');
    pr = cr; pc = cc;
    cc = n / 2 + 1; cr = n / 2 + 1;
    int i = n - 1;
    while(cc != pc) {
        cc--;
        ans[i--] = 'E';
    }
    while(cr != 1) {
        ans[i--] = 'S';
        cr--;
    }
    while(cc != 1) {
        ans[i--] = 'E';
        cc--;
    }
    cout << ans << endl;
}

void solve(int cs, string &path) {
    int n = path.length();
    string ans;
    cout << "Case #" << cs << ": ";
    if(path[n - 1] == 'E') {
        east(path);
    }
    else {
        south(path);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string path;
        cin >> path;
        solve(i + 1, path);
    }
    return 0;
}
