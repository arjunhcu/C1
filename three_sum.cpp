#include <bits/stdc++.h>

using namespace std;

int N = 8;

int main() {
	
	vector<int> v = {1,3,5,7,2,4,6,8};
	sort(v.begin(), v.end());
	
	int K = 4;
	
	for(int i = 0; i <= N-3; i++) {
		int l = i + 1;
		int h = N-1;
		
		while(l < h) {
			if(v[i] + v[l] + v[h] == K) {
				cout<<" found :"<<v[i]<<":"<<v[l]<<":"<<v[h]<<"\n";
				return 0;
			}
			else if (v[i] + v[l] + v[h] > K)
				h--;
			else
				l++;
		} 
	}
	cout<<"Not found :\n";
	return 0;
}