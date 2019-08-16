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

int pa(int a, int b) {
    int c = 0;
    while(a > 0 && a % b == 0) {
        a = a / b;
        c++;
    }
    return c;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    vector<vector<int> > dp2(n + 1, vector<int>(n + 1, INT_MAX)), dp5(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int> > path(n + 1, vector<int>(n + 1, 0));
    dp2[n - 1][n - 1] = pa(mat[n - 1][n - 1], 2);
    dp5[n - 1][n - 1] = pa(mat[n - 1][n - 1], 5);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(min(dp2[i + 1][j], dp5[i + 1][j]) < min(dp2[i][j + 1], dp5[i][j + 1])) {
                dp2[i][j] = dp2[i + 1][j];
                dp5[i][j] = dp5[i + 1][j];
                path[i][j] = 1;
            }
            else {
                dp2[i][j] = dp2[i][j + 1];
                dp5[i][j] = dp5[i][j + 1];
                path[i][j] = 2;
            }
            dp2[i][j] += pa(mat[i][j], 2);
            dp5[i][j] += pa(mat[i][j], 5);
            if(i == n - 1 && j == n - 1) {
                dp2[i][j] = pa(mat[i][j], 2);
                dp5[i][j] = pa(mat[i][j], 5);
                path[i][j] = 0;
            }
        }
    }
    cout << min(dp2[0][0], dp5[0][0]) << endl;
    int i = 0, j = 0;
    while(true) {
        if(path[i][j] == 0)
            break;
        else if(path[i][j] == 1) {
            cout << "D";
            i = i + 1;
        }
        else if(path[i][j] == 2) {
            cout << "R";
            j = j + 1;
        }
    }
    cout << endl;
    return 0;
}
