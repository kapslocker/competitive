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

bool direction(pair<int, int> p1, pair<int, int> p2, pair<int, int> p) {
    return (p.second - p1.second) * (p2.first - p1.first) - (p.first - p1.first) * (p2.second - p1.second);
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<pair<int, int> > > points(4, vector<pair<int, int> > (2));
    vector<int> label(4);
    set<int> x, y;
    for(int i = 0; i < 4; i++) {
        cin >> points[i][0].first >> points[i][0].second;
        cin >> points[i][1].first >> points[i][1].second;
        if(points[i][0].first == points[i][1].first) {
            if(points[i][1].second == points[i][0].second) {
                cout << "NO\n";
                return 0;
            }
            label[i] = 1;
            x.insert(points[i][0].first);
        }
        else if(points[i][0].second == points[i][1].second) {
            label[i] = 0;
            y.insert(points[i][0].second);
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    if(x.size() != 2 || y.size() != 2) {
        cout << "NO\n";
        return 0;
    }
    int ch = 0, cv = 0;
    for(int i = 0; i < 4; i++) {
        label[i] == 0 ? ch++ : cv++;
    }
    if(ch != 2 || cv != 2) {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j || label[i] == label[j])
                continue;
            if((direction(points[i][0], points[i][1], points[j][0]) ^ direction(points[i][0], points[i][1], points[j][1])) == 0) {
                cout << "NO\n";
                return 0;
           }
       }
    }
    cout << "YES\n";
    return 0;
}
