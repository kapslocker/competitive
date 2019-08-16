#include <bits/stdc++.h>
using namespace std;

#define int long long

int t, N, MAX, resp;

int phi(int n) {
    // Number of integers less than n, coprime to n
    int ans = n;
    for(int p = 2; p * p <= n; p++) {
        if(n % p == 0) {
            while(n % p == 0) {
                n = n / p;
            }
            ans -= ans / p;
        }
    }
    if(n > 1) {
        ans -= ans / n;
    }
    return ans;
}

int modpow(int x, int n, int m) {
    if(n == 0)  return 1;
    if(n % 2 == 0) {
        return modpow((x * x) % m, n / 2, m);
    }
    return (x * modpow((x * x) % m, n / 2, m)) % m;
}

int mod_inv(int x, int m, int base) {
    return modpow(x, phi(m) - 1, base);
}

int crt(vector<pair<int, int> > &mods) {
    int m = 1, ans = 0;
    for(auto &p : mods) {
        m *= p.first;
    }
    for(auto &p : mods) {
        int M_i = (m / p.first) % m;
        ans = ans + p.second * M_i * mod_inv(M_i, p.first, m);
        ans = ans % m;
    }
    return ans;
}


int query(int m) {
    for(int i = 0; i < 17; i++) {
        cout << m << " ";
    }
    cout << m << endl;
    fflush(stdout);
    vector<int> res(18); int s = 0;
    for(int i = 0; i < 18; i++) {
        cin >> res[i];  s += res[i];
    }
    return s;
}

int solve() {
    vector<int> choices = {4, 9, 5, 11, 7, 13, 17};
    vector<pair<int, int> > mods;
    for(int c : choices) {
        int sum = query(c);
        mods.push_back({c, sum});
    }
    return crt(mods);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t >> N >> MAX;
    for(int i = 0; i < t; i++) {
        int ans = solve();
        cout << ans << endl;
        fflush(stdout);
        cin >> resp;
        if(resp == -1)
            return 0;
    }
    return 0;
}
