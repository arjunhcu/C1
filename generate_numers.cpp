#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;

vector<int> v = {0,1,2,3,4,5};

static int N = 0;

void fun(int num, int indx) {
	
	if(N >= 10){
		return;
	}
	
	N++;
	cout<<"num :"<<num<<"\n";
	
	for(int i = indx; i < 6; i++) {
		fun(num*10 + v[i], i+1);
	}
}

int main() {
	
	fun(0, 0);
	return 0;
}