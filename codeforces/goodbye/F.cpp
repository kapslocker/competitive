#include <bits/stdc++.h>

using namespace std;

class segment{
public:
    int l, r;
};
int main(){
    int n;
    scanf("%d\n",&n);
    int x;
    char y;
    long long int cost = 0;
    int prevb = INT_MIN, prevr = INT_MIN, prevg = INT_MIN;
    vector<int> rloc, bloc, gloc;
    for(int i = 0; i <n; i++){
        scanf("%d %c\n",&x, &y);
        if(y == 'G'){
            gloc.push_back(x);
        }
        else if(y == 'R'){
            rloc.push_back(x);
        }
        else{
            bloc.push_back(x);
        }
    }
    for(int i = 1; i < gloc.size(); i++){
        cost += gloc[i] - gloc[i-1];
    }
    return 0;
}
