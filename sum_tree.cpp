#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

bool fun(TreeNode* root, int *mysum) {
	
	if(root==NULL) {
		*mysum = 0;
		return true;
	}
	
	if(root->left == NULL && root->right == NULL) {
		*mysum = root->val;
		return true;
	}
	
	int rsum = 0, lsum = 0;
	
	if(fun(root->left, &lsum) && fun(root->right, &rsum) && root->val == lsum + rsum) {
		*mysum = lsum + rsum + root->val;
		return true;
	}
	
	return false;
}




int main() {
	
	
	
	TreeNode *t1 = new TreeNode(26);
	TreeNode *t2 = new TreeNode(10);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(6);
	TreeNode *t6 = new TreeNode(3);
	
	t1->left = t2;
	t1->right = t3;
	
	t2->left = t4;
	t2->right = t5;
	
	t3->right = t6;
	
	
	int mysum = 0;
	
	cout<<" is sum tree : "<<fun(t1, &mysum)<<"and sum : "<<mysum<<"\n";
	
	
	return 0;
}