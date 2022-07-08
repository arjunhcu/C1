#include <bits/stdc++.h>

using namespace std;

int fun(vector<int>&v, int n) {
	
	int x1 = v[0];
	int x2 = 0;
	
	for(int i = 1; i<n; i++)
		x1 = x1^v[i];
	
	for(int i = 1; i <= n; i++)
		x2 = x2^i;
	
	return x1^x2;
	
}

int main() {
	
	int n = 6;
	vector<int> v = {1,2,3,4,5,6};
	
	cout<<"missing :"<<fun(v, n);
	return 0;
}