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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    map<int, vector<int> > inp;
    map<int, vector<int> > hmap;
    vector<int> second;
    bool seen = false;
    for(int i = 0; i < 2 * n; i++) {
        int a, key;
        cin >> key;
        if(inp.find(key) == inp.end()) {
            inp[key].push_back(key);
        }
        else {
            second.push_back(key);
            seen = true;
        }
        hmap[key].push_back(0);
        for(int j = 1; j < n; j++) {
            cin >> a;
            if(!seen)
                inp[key].push_back(a);
            else
                second.push_back(a);
            hmap[a].push_back(j);
        }
        seen = false;
    }
    for(auto &p : hmap) {
        if(p.second[0] == p.second[1]) {
            mat[p.second[0]][p.second[0]] = p.first;
        }
    }
    for(int j = 0; j < n; j++) {
        mat[0][j] = second[j];
    }
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            mat[i][j] = inp[mat[0][j]][i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}
