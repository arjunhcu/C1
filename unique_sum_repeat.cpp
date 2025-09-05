#include <bits/stdc++.h>

using namespace std;

vector<int> v = {1,2,4,3};
int N = 4;


void fun(vector<int>&v, vector<vector<int>>&res, vector<int>&lv, int N, int indx) {
    
    if(N == 0) {
        res.push_back(lv);
        /*for(auto x: lv)
            cout<<" "<<x;
        cout<<"\n";*/
        return;
    }

    for(int i=indx; i<v.size(); i++) {
        if(v[i] <= N) {
            lv.push_back(v[i]);
            fun(v, res, lv, N-v[i], i);
            lv.pop_back();
        }
    }

}


int main() {

    sort(v.begin(), v.end());

    vector<vector<int>> res;
    vector<int> lv;

    fun(v, res, lv, N, 0);
    
    for(auto llv: res) {
        for(auto x: llv)
            cout<<" "<<x;
        cout<<"\n";
    }

    return 0;
}