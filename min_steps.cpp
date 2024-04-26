#include <bits/stdc++.h>

using namespace std;

int fun1(vector<int>&v, int N, vector<int>&r) {
	
	r[0] = 0;
	for(int i =1 ; i < N; i++) {
		for(int j = 0; j < i; j++) {
			if(v[j] >= i - j)
				r[i] = min(r[i], r[j] + 1 < 0 ? INT_MAX : r[j] + 1);
		}
		cout<<"r[i] = "<<r[i]<<"\n";
	}
	
	return r[N -1];
}


int fun(vector<int>&v, int N) {
	vector<int> r(N, INT_MAX);
	return fun1(v, N, r);
}


int main() {
	
	int N =73;
	vector<int> v = {0,2,1,3,27,9,15,7,29,7,3,23,1,19,16,27,16,19,17,30,25,5,29,7,17,12,12,2,18,29,26,13,5,6,20,24,28,25,30,10,23,26,26,23,8,15,26,14,26,0,17,5,28,27,0,18,26,26,10,24,19,5,19,13,6,3,10,21,2,12,16,9,12};
	
	int r = fun(v, N);
	
	cout<<"min jum : "<<r<<"\n";
	
	return 0;
}