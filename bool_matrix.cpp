#include <bits/stdc++.h>

using namespace std;

#define pd pair<int, int>

void fill(int r, int c, int R, int C, int a[][3]) {
	for(int i = 0; i < C; i++)
		a[r][i] = 1;
	
	for(int j=0; j < R; j++)
		a[j][c] = 1;
}

void fun1(int x, int y, int R, int C, int a[][3]) {
	
	queue<pd> q;
	q.push({x,y});
	
	while(!q.empty()) {
		pd p = q.front();
		q.pop();
		
		int r = p.first;
		int c = p.second;
		
		if(r < R && c < C) {
			if(a[r][c] == 1) {
				fill(r, c, R, C, a);
				q.push({r+1, c+1});
			} else {
				q.push({r+1, c});
				q.push({r, c+1});
			}
		}
	}
}

void fun(int R, int C, int a[][3]) {
	
	vector<int> row(R, 0);
	vector<int> col(C,0);
	
	for(int i = 0; i < R; i++) {
		for(int j =0; j < C; j++) {
			if(a[i][j] == 1) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			if(row[i] == 1 || col[j] == 1)
				a[i][j] = 1;
		}
	}
	
	
}

int main() {
	int R = 4, C = 3;
	
	int a[4][3] = {{ 1, 0, 0},
					{ 1, 0, 0},
					{ 1, 0, 0},
					{ 0, 0, 0}};
	
	
	fun(R, C, a);
	
	for(int i = 0 ; i< R; i++) {
		cout<<"{";
		for(int j = 0; j < C; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"}\n";
	}
	
	return 0;
}