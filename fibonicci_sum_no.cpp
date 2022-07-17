#include <bits/stdc++.h>

using namespace std;

int N = 0;

int fun(vector<int>& v, int A) {
	
	vector<int> m(A+1, INT_MAX -1);
	m[0] = 0;
	m[1] = 1;
	int N = v.size();
	
	for(int j = 1; j<= A; j++) {
		for(int i = 0; i <N; i++) {
			if( j - v[i] < 0)
				break;
			m[j] = min(m[j], m[j-v[i]] + 1);
		}
	}
	
	return m[A];
}

int main() {
	
	int A = 804289382/32;//89382/64;
	
	vector<int> v;
	
	int a = 1, b = 1, c = 2;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	
	
	while (c <= A) {
		v.push_back(c);
		a = b;
		b = c;
		c = a + b;
	}
	
	cout<<" minimum coin required : "<<fun(v, A)<<"\n";
	
	return 0;
}