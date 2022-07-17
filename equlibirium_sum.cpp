#include <bits/stdc++.h>

using namespace std;


int fun(vector<int> &v) {
	
	long rsum = 0;
	long lsum = 0;
	
	int N = v.size();
	
	if(N == 1)
		return 0;
	
	for(auto x: v)
		rsum += x;
	
	for(int i  = 0; i< N; i++) {
		rsum -= v[i];
		
		if(lsum == rsum)
			return i;
		
		lsum += v[i];
	}
	
	return -1;
}


int main(){
	
	vector<int> v = {-7, 1, 5, 2, -4, 3, 0};
	cout<<"eq index : "<<fun(v)<<"\n";
	return 0;
}
