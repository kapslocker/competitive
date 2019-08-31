#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int t, n, k;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        int height = n / k;
        if(height % k == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}