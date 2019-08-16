#include <iostream>
#include <cmath>

using namespace std;

int count_pow(double l, double r, int p){
    int a = pow(l, 1/p), b = pow(r, 1/p);
    int count = b - a;
    cout << a << " " << b << endl;
    if(fabs(pow(a, p) - l)< 1e-6)
        count++;
    return count;
}
int main(){
    int l, r, q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        int ans = 0;
        for(int p = 2; p <= 18; p++){
            ans += count_pow(l, r, p);
        }
        cout << ans << endl;
    }
    return 0;
}
