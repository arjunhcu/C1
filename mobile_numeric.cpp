#include <bits/stdc++.h>

using namespace std;

long long fun(int n) {
	
	long long res = 0;
	
	unordered_map<int, int> m;
	
	res = 1*pow(2, n-1) + 4*pow(3, n-1) + 3*pow(4, n-1) + 2*pow(5, n-1);
	
	return res;
	
}

int main() {
	
	int n = 4;
	cout<<"output : "<<fun(n)<<"\n";
	return 0;
}