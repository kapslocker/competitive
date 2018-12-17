#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int isprime(int n) {
    if(n < 2)
        return false;
    if(n == 2 || n == 3)
        return true;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    for(int i = 5; i <= sqrt(n); i+= 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void fill(vector<int> &ans, int times, int p) {
    cout << "debug " << times << " " << p << endl;
    int num = times / (p - 1);
    times = times - num * (p - 1);
    for(int i = 0; i < num; i++) {
        ans.push_back(p - 1);
    }
    if(times)
        ans.push_back(times);
}
int main() {
    int n;
    cin >> n;
    if(isprime(n)) {
        cout << "NO\n";
        return 0;
    }
    int p, q;
    for(p = floor(sqrt(n)); p > 1; p--) {
        if(isprime(p) && n % p == 0)
            break;
    }
    int r = n / p;
    while(r % p == 0) {
        r = r /  p;
    }
    if(r == 1) {
        cout << "NO\n";
        return 0;
    }

    for(q = 2; q < r; q++) {
        if(isprime(q) && r % q == 0)
            break;
    }
    int tp = 0, tq = 0, rem;
    while((tp * p) % q != q - 1) {
        tp++;
    }
    rem = n - 1 - tp * p;
    tq = rem / q;
    vector<int> a, b;
    fill(a, tp, q);
    fill(b, tq, p);
    cout << a.size() + b.size() << endl;
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " " << q << endl;
    }
    for(int i = 0; i < b.size(); i++) {
        cout << b[i] << " " << p << endl;
    }
    return 0;
}
