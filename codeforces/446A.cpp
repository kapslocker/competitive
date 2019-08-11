#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int dfs(int n, int m) {
    if(m == n)
        return 0;
    if(n <= 0)
        return INT_MAX;
    cout << n << " " << m << endl;
    int a = dfs(n - 1, m), b = dfs(2 * n, m);
    return 1 + min(a, b);
}
int main() {
    int n, m;
    cin >> n >> m;
    cout <<dfs(n, m) << endl;
    return 0;
}
