#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a, b, c, x, y, z, u;
    cin >> a >> b >> c;
    int dp[4001] = {0};
    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;
    for(int i = 0; i <= n; i++){
        x = i >= a ? dp[i - a] : 0;
        y = i >= b ? dp[i - b] : 0;
        z = i >= c ? dp[i - c] : 0;
        u = max(x, max(y, z));
        if(u)
            dp[i] = 1 + u;
    }
    cout << dp[n] << endl;
    return 0;
}
