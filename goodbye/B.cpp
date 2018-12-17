#include <bits/stdc++.h>

using namespace std;

vector<string> direction;
int rows, cols;
pair<int, int> start;

char mat[50][50];

bool find(string s, char x){
	for(char a : s){
		if(a==x) return true;
	}
	return false;
}

void recurse(string str, int len){
	if(len == 4){
		direction.push_back(str);
		return;
	}
	for(char x : {'u', 'd', 'l', 'r'}){
		if(!find(str, x)){
			recurse(str+x, len+1);
		}
	}
}

int getPosX(char x, int pos){
	if(x=='u') return pos-1;
	if(x=='d') return pos+1;
	return pos;
}

int getPosY(char x, int pos){
	if(x=='l') return pos-1;
	if(x=='r') return pos+1;
	return pos;
}

bool checkx(int p){
	if(p>=0 and p<rows) return true;
	return false;
}

bool checky(int p){
	if(p>=0 and p<cols) return true;
	return false;
}

bool checkMap(int id, string inp){
	// cout<<id<<" New Map "<<direction[id]<<endl;
	unordered_map<char, char> mp;
	mp['0'] = direction[id][0];
	mp['1'] = direction[id][1];
	mp['2'] = direction[id][2];
	mp['3'] = direction[id][3];
	int posx = start.first;
	int posy = start.second;
	// cout<<posx<<" "<<posy<<endl;
	// if(mat[posx][posy] == 'E') return true;
	for(char x : inp){
		x = mp[x];
		posx = getPosX(x, posx);
		posy = getPosY(x, posy);
		// cout<<posx<<" "<<posy<<endl;
		if(checkx(posx) and checky(posy)){
			if(mat[posx][posy] == '#') return false;
		}
		else{
			return false;
		}
		if(mat[posx][posy] == 'E') return true;
		// cout<<posx<<" "<<posy<<" ";
		// cout<<checkx(posx)<<" "<<checky(posx)<<endl;
	}
	if(mat[posx][posy] == 'E') return true;
	return false;
}

int main(){
	recurse("", 0);
	cin>>rows>>cols;
	// cout<<rows<<cols<<endl;
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			char x;
			cin>>x;
			if(x=='S'){
				start.first = i;
				start.second = j;
			}
			mat[i][j] = x;
		}
	}
	// for(string a : direction){
	// 	cout<<a<<endl;
	// }
	string inp;
	cin>>inp;
	int ans = 0;
	for(int i = 0; i<24; i++){
		if(checkMap(i, inp)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
