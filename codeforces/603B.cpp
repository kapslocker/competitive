#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int modpow(int x, int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(n % 2 == 0)
        return modpow((x * x) % mod, n / 2);
    return (x * modpow((x * x) % mod, n / 2)) % mod;
}

int order(int k, int p) {
    int m = (k * k) % p, steps = 1;
    while(m != k) {
        m = (m * k) % p;
        steps++;
    }
    return steps;
}

int32_t main() {
    int p, k;
    cin >> p >> k;
    if(k == 0) {
        cout << modpow(p, p - 1) << endl;
    }
    else if(k == 1) {
        cout << modpow(p, p) << endl;
    }
    else {
        int m = order(k, p);
        cout << modpow(p, (p - 1) / m) << endl;
    }
    return 0;
}
