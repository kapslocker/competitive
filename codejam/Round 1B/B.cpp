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

vector<double> eval(vector<vector<double> > &A, vector<double> &B) {
    vector<double> ans(6, 0.0);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            ans[i] = ans[i] + A[i][j] * B[j];
        }
    }
    return ans;
}

vector<double> solvesmall() {
    vector<double> B(6);
    vector<vector<double> > mat =  {{0.1, -0.1, -0.05, 0.0, 0.0, 0.025},
                                    {-1.2, 1.2, 0.1, 0.0, 0.0, -0.05},
                                    {-0.4, -0.6, 1.2, 0.0, 0.0, -0.1},
                                    {1.6, -1.6, -0.8, 1.0, 0.0, -0.1},
                                    {-1.6, 1.6, 0.8, -1.0, 1.0, -0.4},
                                    {2.4, -0.4, -1.2, 0.0, -1.0, 0.6}};

    for(int i = 1; i <= 6; i++) {
        cout << i << endl;  fflush(stdout);
        cin >> B[i-1];
        if(B[i-1] == -1) {
            exit(0);
        }
    }
    vector<double> ans = eval(mat, B);
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, w, resp;
    cin >> t >> w;
    for(int k = 0; k < t; k++) {
        vector<double> ans = solvesmall();
        for(int i = 0; i < 6; i++) {
            cout << (int)std::round(ans[i]) << " ";
        }
        cout << endl;
        fflush(stdout);
        cin >> resp;
        if(resp != 1)
            return 0;
    }
    return 0;
}
