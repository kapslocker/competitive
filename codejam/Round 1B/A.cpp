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

void add(vector<vector<int> > &arr, int x1, int y1, int x2, int y2) {
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++)
            arr[i][j]++;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int jj = 0; jj < t; jj++) {
        int n, N, maxv = INT_MIN, x_ans, y_ans;
        cin >> n >> N;
        vector<vector<int> > arr(N + 1, vector<int>(N + 1, 0));
        for(int i = 0; i < n; i++) {
            int x, y;
            char d;
            cin >> x >> y >> d;
            if(d == 'N')    add(arr, 0, y + 1, N, N);
            else if(d == 'S') add(arr, 0, 0, N, y - 1);
            else if(d == 'E') add(arr, x + 1, 0, N, N);
            else add(arr, 0, 0, x - 1, N);
        }
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= N; j++) {
                if(arr[i][j] > maxv) {
                    maxv = arr[i][j];
                    x_ans = i;  y_ans = j;
                }
            }
        }
        cout << "Case #" << jj + 1 << ": " << x_ans << " " << y_ans << endl;
    }
    return 0;
}
