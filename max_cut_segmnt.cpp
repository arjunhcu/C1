#include <bits/stdc++.h>

using namespace std;

 int fun(int l, int x, int y, int z, vector<int>& dp) {
        
        if(l == 0)
            return 0;
        
        if(dp[l] != -1)
            return dp[l];
        
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        
        if(l - x >= 0)
            a = fun(l -x, x, y, z, dp) + 1;
        if(l - y >= 0)
            b = fun(l-y, x, y, z, dp) + 1 ;
        if(l - z >= 0)
            c = fun(l-z, x, y, z, dp) + 1;
        
        dp[l] = max(a, max(b,c));
        return dp[l];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[n] = fun(n, x, y, z, dp);
        return dp[n] < 0 ? 0 : dp[n];
    }

int main() {
	
	int N = 4, x =2, y =1, z=1;
	return maximizeTheCuts(N, x, y, z);
	
}