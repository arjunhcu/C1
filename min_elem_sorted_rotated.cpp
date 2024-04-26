#include <bits/stdc++.h>

using namespace std;



int fun(vector<int>& v) {
	
	int N = v.size(), l = 0, h = N-1;
	
	if(l == h)
		return v[0];
	
	//Case if no rotation
	if(v[l] <= v[h])
		return v[l];
	
	while(l < h) {
		
		int mid = (h - l)/2 + l;
		
		if(mid < N && v[mid] <= v[l])
			h = mid;
		else
			l = mid + 1;
	}
	
	return v[l];
}

int main() {
	
	vector<int> v = {4,5,6,7,8,3};
	
	cout<<"min elem :"<<fun(v)<<"\n";
	
	return 0;
}