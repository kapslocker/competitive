#include <iostream>
#include <vector>
using namespace std;

void printpoly(int n, vector<vector<int> > &arr){
    cout << n << endl;
    for(int i = 0; i <= n; i++){
        cout << arr[n][i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int> > poly(n + 1, vector<int>(n + 1, 0));
    poly[0][0] = 1;
    poly[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= n; j++){
            poly[i][j] = ((j > 0 ? poly[i-1][j-1] : 0) + poly[i-2][j]) % 2;
        }
    }
    printpoly(n, poly);
    printpoly(n - 1, poly);
    return 0;
}
