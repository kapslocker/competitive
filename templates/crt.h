#include <vector>

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

int crt(std::vector<std::pair<int, int> > &mods) {
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
