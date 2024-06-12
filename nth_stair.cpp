#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000000 + 7)

int main() {
	
	int n = 84;
	
	if (n == 0 || n ==1 || n ==2)
            return n;
        
	int a = 1, b = 2, c = 0;
	
	for(int i = 3; i <= n;  i++) {
		c = (a + b) % MOD;
		a = b ;
		b = c ;
	}
    
	cout<<"c = "<<c %MOD<<"\n";
    return c % MOD;
}