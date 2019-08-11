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

void fail() {
    cout << -1 << endl;
    exit(0);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    string s;
    cin >> n >> s;
    int px = 0, py = 0;
    int fx = x2 - x1, fy = y2 - y1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            if(fx < 0) {
                px += 2;
                py++;
            }
        }
        if(s[i] == 'U') {
            if(fy > 0) {
                py += 2;
                px++;
            }
        }
        if(s[i] == 'R') {
            if(fx > 0) {
                px += 2;
                py++;
            }
        }
        if(s[i] == 'D') {
            if(fy < 0) {
                py += 2;
                px++;
            }
        }
    }
    if(px == 0 && fx != 0)  fail();
    if(py == 0 && fy != 0)  fail();
    int sgnx, sgny;
    if(fx == 0)
        sgnx = 0;
    else
        sgnx = fx / abs(fx);
    if(fy == 0)
        sgny = 0;
    else
        sgny = fy / abs(fy);

    fx = abs(fx);   fy =abs(fy);
    int k = 0;
    for(k = 0; ; k++) {
        if(fx <= px && fy <= py)
            break;
        fx -= px; fy -= py;
    }
    debug(k, fx, fy);
    if(fx > 0 || fy > 0) {
        int step = 0;
        for(int i = 0; i < n; i++) {
            if(fx <= 0 && fy <= 0)
                break;
            step++;
            if(s[i] == 'L') {
                if(sgnx < 0) {fx -= 2; fy -= 1;}
            }
            if(s[i] == 'R') {
                if(sgnx > 0) {fx -= 2; fy -= 1;}
            }
            if(s[i] == 'U') {
                if(sgny > 0) { fy -= 2; fx -= 1;}
            }
            if(s[i] == 'D') {
                if(sgny < 0) {fy -= 2; fx -= 1;}
            }
            debug(i, fx, fy, step);
        }
        cout << k * n + step << endl;
        return 0;
    }
    cout << k * n << endl;
    return 0;
}
